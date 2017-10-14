'''
An extension of my matrix class I wrote for Cracking The Coding Interview problems.

This shouldn't be used for anything important. It's slow...use numpy! It's just
for experimental purposes.
'''


from itertools import zip_longest
import operator

class Matrix(object):
    def __init__(self, data):
        self.rows = len(data)
        self.cols = len(data[0])
        self.mat = data
    def __str__(self):
        '''
        For automatically converting to string or printing
        '''
        return str(self.mat)
    def __getitem__(self, item):
        return self.mat[key]
    def __setitem__(self, key, value):
        self.mat[key] = value
    def __eq__(self, other):
        '''
        Operator overload for comparisons
        '''
        return self.mat == other.get_matrix()
    def get_rows(self):
        return self.rows
    def get_cols(self):
        return self.cols
    def get_matrix(self):
        return self.mat
    def transpose(self):
        self.mat = list(map(list, zip(*self.mat)))
        self.rows = len(self.mat)
        self.cols = len(self.mat[0])
        return self
    def T(self):
        return self.transpose()
    def rotate_90deg_cw(self):
        for i in range(self.rows):
            self.mat[i] = self.mat[i][::-1]
        return self
    def is_square(self):
        return self.rows == self.cols
    @staticmethod
    def transpose(mat):
        return list(map(list, zip_longest(*mat)))
    @staticmethod
    def rotate_90deg_cw(mat):
        for i in range(mat.rows):
            mat[i] = mat[i][::-1]
        return mat