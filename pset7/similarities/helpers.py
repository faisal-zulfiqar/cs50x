from nltk.tokenize import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""

    strs_a = a.splitlines()
    strs_b = b.splitlines()
    
    common = []
    
    for line in strs_a:
        if line in strs_b:
            if line not in common:
                common.append(line)
    for line in strs_b:
        if line in strs_a:
            if line not in common:
                common.append(line)
    return common


def sentences(a, b):
    """Return sentences in both a and b"""
    sentences_a = sent_tokenize(a)
    sentences_b = sent_tokenize(b)
    
    common = []
    
    for sentence in sentences_a:
        if sentence in sentences_b:
            if sentence not in common:
                common.append(sentence)
    for sentence in sentences_b:
        if sentence in sentences_a:
            if sentence not in common:
                common.append(sentence)
    return common


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    strs_a = a.splitlines()
    strs_b = b.splitlines()
    
    substrs_a = []
    substrs_b = []
    
    common = []
    
    for string in strs_a:
        for i in range(len(string) - n):
            substrs_a.append(string[i:n])
    for string in strs_b:
        for j in range(len(string) - n):
            substrs_b.append(string[j:n])
    
    for substr in substrs_a:
        if substr in substrs_b:
            if substr not in common:
                common.append(substr)
                
    for substr in substrs_b:
        if substr in substrs_a:
            if substr not in common:
                common.append(substr)
    
    return common
