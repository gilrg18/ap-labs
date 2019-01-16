#Given a string, find the length of 
#the longest substring without repeating characters.
#Gilberto Rogel García A01630171
def longestSub(x):
    n = len(x)
    length = 0
    for i in range(n):
        seen = set()
        for j in range(i, n):
            if x[j] in seen: break
            seen.add(x[j])
        length = max(len(seen), length)
    return length

print(longestSub("pwwkew"))
print(longestSub("bbbbbb"))
print(longestSub("abcabcbb"))