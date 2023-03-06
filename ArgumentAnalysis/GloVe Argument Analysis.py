# This Python 3 environment comes with many helpful analytics libraries installed
# It is defined by the kaggle/python Docker image: https://github.com/kaggle/docker-python
# For example, here's several helpful packages to load
# https://www.kaggle.com/code/dhirendra73/starter-tfidf-xgboost-to-glove-bilstm/notebook

import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)

# Input data files are available in the read-only "../input/" directory
# For example, running this (by clicking run or pressing Shift+Enter) will list all files under the input directory

import os
for dirname, _, filenames in os.walk('/kaggle/input'):
    for filename in filenames:
        pass

# You can write up to 20GB to the current directory (/kaggle/working/) that gets preserved as output when you create a version using "Save & Run All" 
# You can also write temporary files to /kaggle/temp/, but they won't be saved outside of the current session

import numpy as np
import pandas as pd
from time import time
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer
from bs4 import BeautifulSoup
import shutil
import gensim
import re
import spacy

import tensorflow as tf
from tensorflow import keras
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import LSTM, GRU,SimpleRNN
from tensorflow.keras.layers import Dense, Activation, Dropout
from tensorflow.keras.layers import Embedding
from tensorflow.keras.layers import BatchNormalization
from tensorflow.python.keras.utils import np_utils
from sklearn import preprocessing, decomposition, model_selection, metrics, pipeline
from tensorflow.keras.layers import GlobalMaxPooling1D, Conv1D, MaxPooling1D, Flatten, Bidirectional, SpatialDropout1D
from tensorflow.keras.preprocessing import sequence, text
from tensorflow.keras.callbacks import EarlyStopping

import matplotlib.pyplot as plt
import seaborn as sns
%matplotlib inline
from plotly import graph_objs as go
import plotly.express as px
import plotly.figure_factory as ff

# Detect hardware, return appropriate distribution strategy
try:
    # TPU detection. No parameters necessary if TPU_NAME environment variable is
    # set: this is always the case on Kaggle.
    tpu = tf.distribute.cluster_resolver.TPUClusterResolver()
    print('Running on TPU ', tpu.master())
except ValueError:
    tpu = None

if tpu:
    tf.config.experimental_connect_to_cluster(tpu)
    tf.tpu.experimental.initialize_tpu_system(tpu)
    strategy = tf.distribute.experimental.TPUStrategy(tpu)
else:
    # Default distribution strategy in Tensorflow. Works on CPU and single GPU.
    strategy = tf.distribute.get_strategy()

print("REPLICAS: ", strategy.num_replicas_in_sync)

train_df = pd.read_csv("../input/feedback-prize-effectiveness/train.csv")
test_df = pd.read_csv("../input/feedback-prize-effectiveness/test.csv")
submission_sample = pd.read_csv("../input/feedback-prize-effectiveness/sample_submission.csv")

train_df.sample(10)

train_df.info()

train_df.isnull().sum()

train_df.shape
test_df.shape

train_df["discourse_type"].value_counts().plot(kind='bar')

plt.figure(figsize=(10,4))
sns.countplot(x='discourse_type', data=train_df)
plt.show()

plt.figure(figsize=(10,4))
sns.countplot(x='discourse_effectiveness', data=train_df)
plt.show()

nlp = spacy.load('en_core_web_sm')

def preprocess(q):
    
    q = str(q).lower().strip()
    contractions = { 
    "ain't": "am not",
    "aren't": "are not",
    "can't": "can not",
    "can't've": "can not have",
    "'cause": "because",
    "could've": "could have",
    "couldn't": "could not",
    "couldn't've": "could not have",
    "didn't": "did not",
    "doesn't": "does not",
    "don't": "do not",
    "hadn't": "had not",
    "hadn't've": "had not have",
    "hasn't": "has not",
    "haven't": "have not",
    "he'd": "he would",
    "he'd've": "he would have",
    "he'll": "he will",
    "he'll've": "he will have",
    "he's": "he is",
    "how'd": "how did",
    "how'd'y": "how do you",
    "how'll": "how will",
    "how's": "how is",
    "i'd": "i would",
    "i'd've": "i would have",
    "i'll": "i will",
    "i'll've": "i will have",
    "i'm": "i am",
    "i've": "i have",
    "isn't": "is not",
    "it'd": "it would",
    "it'd've": "it would have",
    "it'll": "it will",
    "it'll've": "it will have",
    "it's": "it is",
    "let's": "let us",
    "ma'am": "madam",
    "mayn't": "may not",
    "might've": "might have",
    "mightn't": "might not",
    "mightn't've": "might not have",
    "must've": "must have",
    "mustn't": "must not",
    "mustn't've": "must not have",
    "needn't": "need not",
    "needn't've": "need not have",
    "o'clock": "of the clock",
    "oughtn't": "ought not",
    "oughtn't've": "ought not have",
    "shan't": "shall not",
    "sha'n't": "shall not",
    "shan't've": "shall not have",
    "she'd": "she would",
    "she'd've": "she would have",
    "she'll": "she will",
    "she'll've": "she will have",
    "she's": "she is",
    "should've": "should have",
    "shouldn't": "should not",
    "shouldn't've": "should not have",
    "so've": "so have",
    "so's": "so as",
    "that'd": "that would",
    "that'd've": "that would have",
    "that's": "that is",
    "there'd": "there would",
    "there'd've": "there would have",
    "there's": "there is",
    "they'd": "they would",
    "they'd've": "they would have",
    "they'll": "they will",
    "they'll've": "they will have",
    "they're": "they are",
    "they've": "they have",
    "to've": "to have",
    "wasn't": "was not",
    "we'd": "we would",
    "we'd've": "we would have",
    "we'll": "we will",
    "we'll've": "we will have",
    "we're": "we are",
    "we've": "we have",
    "weren't": "were not",
    "what'll": "what will",
    "what'll've": "what will have",
    "what're": "what are",
    "what's": "what is",
    "what've": "what have",
    "when's": "when is",
    "when've": "when have",
    "where'd": "where did",
    "where's": "where is",
    "where've": "where have",
    "who'll": "who will",
    "who'll've": "who will have",
    "who's": "who is",
    "who've": "who have",
    "why's": "why is",
    "why've": "why have",
    "will've": "will have",
    "won't": "will not",
    "won't've": "will not have",
    "would've": "would have",
    "wouldn't": "would not",
    "wouldn't've": "would not have",
    "y'all": "you all",
    "y'all'd": "you all would",
    "y'all'd've": "you all would have",
    "y'all're": "you all are",
    "y'all've": "you all have",
    "you'd": "you would",
    "you'd've": "you would have",
    "you'll": "you will",
    "you'll've": "you will have",
    "you're": "you are",
    "you've": "you have"
    }

    q_decontracted = []

    for word in q.split():
        if word in contractions:
            word = contractions[word]

        q_decontracted.append(word)

    q = ' '.join(q_decontracted)
    q = q.replace("'ve", " have")
    q = q.replace("n't", " not")
    q = q.replace("'re", " are")
    q = q.replace("'ll", " will")
    
        # Remove punctuations
    pattern = re.compile('\W')
    q = re.sub(pattern, ' ', q).strip()

    
    return q

train_df['discourse_text'] = train_df['discourse_text'].apply(lambda x: preprocess(x))

from sklearn.preprocessing import LabelEncoder
label_encoder = LabelEncoder()
train_df['discourse_effectiveness'] = label_encoder.fit_transform(train_df['discourse_effectiveness'])

discourse_type = list(set(train_df['discourse_type'].values))

discourse_type

train_df['text'] = train_df["discourse_text"] +' '+  train_df["discourse_type"]

y = train_df['discourse_effectiveness']

train_df = train_df.drop(['discourse_text','discourse_id','essay_id','discourse_type' ],axis=1)

X = train_df['text']

from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(X, y,
    test_size = 0.2, random_state = 4)

tfv = TfidfVectorizer(min_df=3,  max_features=None, 
    strip_accents='unicode', analyzer='word',token_pattern=r'\w{1,}',
    ngram_range=(1, 3), use_idf=1,smooth_idf=1,sublinear_tf=1,
    stop_words = 'english')

# Fitting TF-IDF to both training and test sets (semi-supervised learning)
tfv.fit(list(X_train) + list(X_test))
xtrain_tfv =  tfv.transform(X_train) 
xvalid_tfv = tfv.transform(X_test)

from xgboost import XGBClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.multioutput import MultiOutputClassifier, MultiOutputRegressor
from sklearn.linear_model import LogisticRegression
from sklearn.svm import SVC

y_train

from xgboost import XGBClassifier
xgb = XGBClassifier()
xgb.fit(xtrain_tfv,y_train)

_pred = xgb.predict(xvalid_tfv)
from sklearn.metrics import accuracy_score
xgb_score = accuracy_score(y_test, y_pred)
print(xgb_score)
0.6553787569699442
#BOW approach
from sklearn.feature_extraction.text import CountVectorizer
cv = CountVectorizer(max_features=300)
cv.fit(X_train)

xtrain_cv = cv.transform(X_train).toarray()
xtest_cv = cv.transform(X_test).toarray()
from xgboost import XGBClassifier
xgb = XGBClassifier()
xgb.fit(xtrain_cv,y_train)

y_pred_cv = xgb.predict(xtest_cv)
xgb_score_cv = accuracy_score(y_test, y_pred_cv)
print(xgb_score_cv)
0.6567387460900312
from sklearn.naive_bayes import MultinomialNB
model1 = MultinomialNB().fit(xtrain_tfv,y_train)
y_pred1 = model1.predict(xvalid_tfv)
from sklearn.metrics import accuracy_score, classification_report
print(accuracy_score(y_test,y_pred1))
print(classification_report(y_pred1,y_test))

y.nunique()

from tensorflow.keras.preprocessing.text import Tokenizer
tokenizer = Tokenizer()
tokenizer.fit_on_texts(X)

X = tokenizer.texts_to_sequences(X)
maxlen = 500
from tensorflow.keras.preprocessing.sequence import pad_sequences
X = pad_sequences(X, maxlen=maxlen)
word_index = tokenizer.word_index
vocab_size = len(tokenizer.word_index) + 1
def get_weights_matrix(model,vocab,) :
    weights_matrix = np.zeros((vocab_size, DIM))
    for word, i in vocab.items():
        if word in list(model.wv.key_to_index):
            weights_matrix[i] = model.wv[word]
        
    return weights_matrix
# Train test split
X_train, X_test, y_train, y_test = train_test_split(X, y)
# load the GloVe vectors in a dictionary:

embeddings_index = {}
f = open('/kaggle/input/glove840b300dtxt/glove.840B.300d.txt','r',encoding='utf-8')
for line in f:
    values = line.split(' ')
    word = values[0]
    coefs = np.asarray([float(val) for val in values[1:]])
    embeddings_index[word] = coefs
f.close()

print('Found %s word vectors.' % len(embeddings_index))

embedding_matrix = np.zeros((len(word_index) + 1, 300))

for word, i in word_index.items():
    embedding_vector = embeddings_index.get(word)
    if embedding_vector is not None:
        embedding_matrix[i] = embedding_vector

from tensorflow.keras.callbacks import ReduceLROnPlateau, ModelCheckpoint, EarlyStopping
callbacks = [EarlyStopping(monitor='val_loss', patience=5, verbose=1),
    ModelCheckpoint('model.hdf5',
    save_best_only=True)]

# # detect and init the TPU
# tpu = tf.distribute.cluster_resolver.TPUClusterResolver.connect()

# # instantiate a distribution strategy
# tpu_strategy = tf.distribute.experimental.TPUStrategy(tpu)

# # instantiating the model in the strategy scope creates the model on the TPU
# with tpu_strategy.scope():
model = Sequential()
model.add(Embedding(len(word_index) + 1,
    300,
    weights=[embedding_matrix],
    input_length=1500,
    trainable=True))
model.add(Bidirectional(LSTM(300, dropout=0.3, recurrent_dropout=0.3)))

model.add(Dense(64, activation='relu'))

model.add(Dense(3,activation='softmax'))
model.compile(loss='sparse_categorical_crossentropy', optimizer='adam',metrics=['accuracy'],)

# train model normally
model.fit(X_train, y_train, validation_split=0.3, batch_size = 128, epochs=6,callbacks = callbacks)

test_df.head()

test_data = test_df['discourse_text']+' '+ test_df['discourse_type']
test_data = tokenizer.texts_to_sequences(test_data)
test_data = pad_sequences(test_data, maxlen=maxlen)
pred = model.predict(test_data)
submission_sample.loc[:,"Ineffective"] = pred[:,0]
submission_sample.loc[:,"Adequate"] = pred[:,1]
submission_sample.loc[:,"Effective"] = pred[:,2]
submission_sample.to_csv('submission.csv',index=False)
submission_sample.head()