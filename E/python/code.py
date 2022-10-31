def anagram(s1, s2):
    if len(s1) != len(s2):
        return False
    else:
        return sorted(s1) == sorted(s2)
