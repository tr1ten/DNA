def findLongestRegex(x, y, z):
    n = len(x)
    ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    regex = []

    for i in range(n):
        a, b = x[i], y[i]
        if a == b:
            regex.append([a])
        else:
            regex.append(list(ALPHABET))

    if matches(regex, z):
        for i in range(n):
            if len(regex[i]) == 1:
                continue
            if z[i] in regex[i]:
                regex[i].remove(z[i])
                if not matches(regex, z):
                    break
                regex[i].insert(0, z[i])
        if matches(regex, z):
            return "-1"

    result = []
    for r in regex:
        if len(r) == 1:
            result.append(r[0])
        else:
            result.append("[" + ''.join(r) + "]")

    return ''.join(result)

def matches(regex, z):
    for i in range(len(z)):
        if z[i] not in regex[i]:
            return False
    return True