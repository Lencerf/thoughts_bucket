import unittest
from random import randrange
from sort import merge_sort, insertion_sort, heap_sort

class TestSorting(unittest.TestCase):
    def setUp(self):
        self.test_array1 = [randrange(100) for n in range(100)]
        self.test_array = [a for a in self.test_array1]
        self.test_array1.sort()
        self.sorted_array = self.test_array1

    def test_merge_sort(self):
        merge_sorted_array = merge_sort(self.test_array)
        self.assertEqual(self.sorted_array, merge_sorted_array)
    
    def test_insertion_sort(self):
        test_array_backup = [a for a in self.test_array]
        insertion_sort(test_array_backup)
        self.assertEqual(self.sorted_array, test_array_backup)
    
    def test_heap_sort(self):
        test_array_backup = [a for a in self.test_array]
        heap_sort(test_array_backup)
        self.assertEqual(self.sorted_array, test_array_backup)

if __name__ == '__main__':
    unittest.main()

