from textblob import TextBlob

def analyze_sentiment(text):

    blob = TextBlob(text)

    polarity = blob.sentiment.polarity

    if polarity > 0:
        sentiment = 'Positive'
    elif polarity < 0:
        sentiment = 'Negative'
    else:
        sentiment = 'Neutro'

    print(f'Text: {text}')
    print(f'Polarity: {polarity}')
    print(f'Sentiment: {sentiment}')

text_example = 'You are nice'
analyze_sentiment(text_example)