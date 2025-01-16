#!/usr/bin/python3
"""
Count words in Reddit hot article titles using recursion.
"""
import requests


def count_words(subreddit, word_list, word_count={}, after=None):
    """
    Recursive function to count occurrences of words in hot article
    titles from a subreddit.
    Args:
        subreddit (str): Name of the subreddit to query.
        word_list (list): List of keywords to count.
        word_count (dict): Dictionary to store counts of keywords.
        after (str): Token for paginated results (default: None).
    Returns:
        None: Prints sorted counts of words.
    """
    # Prepare headers for the Reddit API request
    headers = {'User-Agent': 'python:count_words:v1.0 (by /u/yourusername)'}
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    params = {'limit': 100, 'after': after}

    # Make the HTTP GET request
    response = requests.get(url, headers=headers,
                            params=params, allow_redirects=False)

    # Check if the subreddit is valid
    if response.status_code != 200:
        return

    # Parse the JSON response
    data = response.json().get('data', {})
    children = data.get('children', [])
    after = data.get('after', None)

    # Initialize word_count for first recursion
    if not word_count:
        word_count = {word.lower(): 0 for word in word_list}

    # Process titles of the current batch of posts
    for child in children:
        title = child.get('data', {}).get('title', '').lower()
        words = title.split()
        for word in words:
            # Remove non-alphabetic characters from the word
            clean_word = ''.join(filter(str.isalpha, word))
            if clean_word in word_count:
                word_count[clean_word] += 1

    # Continue to the next page if available
    if after:
        count_words(subreddit, word_list, word_count, after)
    else:
        # Sort and print results
        sorted_counts = sorted(word_count.items(), key=lambda x: (-x[1], x[0]))
        for word, count in sorted_counts:
            if count > 0:
                print(f"{word}: {count}")
