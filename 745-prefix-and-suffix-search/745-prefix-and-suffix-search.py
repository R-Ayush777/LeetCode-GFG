class WordFilter(object):

    def __init__(self, words):
        self.inputs = {}
        for index, word in enumerate(words):
            prefix = ''
            for char in [''] + list(word):
                prefix += char
                suffix = ''
                for char in [''] + list(word[::-1]):
                    suffix += char
                    self.inputs[prefix + '.' + suffix[::-1]] = index

    def f(self, prefix, suffix):
        return self.inputs.get(prefix + '.' + suffix, -1)


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)