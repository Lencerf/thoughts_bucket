from random import randrange

def test_sorted_array(array):
    for i in range(0, len(array)-1):
        if array[i] > array[i+1]:
            return False
    return True

def insertion_sort(array):
    for i in range(1,len(array)):
        for j in range(i-1, -1, -1):
            if array[j] > array[j+1]:
                temp = array[j]
                array[j] = array[j+1]
                array[j+1] = temp
            else:
                break

def merge(left, right):
    if left is None or len(left) == 0:
        return right
    if right is None or len(right) == 0:
        return left
    temp = [0 for n in range(len(left)+len(right))]
    i = 0
    j = 0
    for k in range(len(temp)):
        if j == len(right) or (i < len(left) and left[i] <= right[j]):
            temp[k] = left[i]
            i += 1
        else:
            temp[k] = right[j]
            j += 1
    return temp
    for index, k in enumerate(temp):
        if index < len(left):
            left[index] = k
        else:
            right[index-len(left)] = k




def merge_sort(array):
    if len(array) <= 1:
        return array
    left = array[0:len(array)//2]
    right = array[len(array)//2:]
    sorted_left = merge_sort(left)
    sorted_right = merge_sort(right)
    return merge(sorted_left, sorted_right)

def max_heapify(array,i, length):
    #print("before max heapify",f"{array}, i={i}, length={length}")
    if 2*i+1 > length-1: # no left leaf = no leaves
        #print("no leaf")
        pass # leaves are good
    elif 2*i+2 > length-1: # only left leaf
        #print("only left leaf")
        if array[2*i+1] > array[i]:
            temp = array[2*i+1]
            array[2*i+1] = array[i]
            array[i] = temp
            max_heapify(array, 2*i+1, length)
    else:
        #print("two leaf")
        if array[2*i+1] > array[i] and array[2*i+1] >= array[2*i+2]:
            #print("left is larger")
            temp = array[2*i+1]
            array[2*i+1] = array[i]
            array[i] = temp
            max_heapify(array, 2*i+1, length)
        elif array[2*i+2] > array[i] and array[2*i+2] >= array[2*i+1]:
            #print("right is larger")
            temp = array[2*i+2]
            array[2*i+2] = array[i]
            array[i] = temp
            max_heapify(array, 2*i+2, length)
    #print("after  max heapify",f"{array}, i={i}, length={length}")


def build_max_heap(array):
    for i in range(len(array)//2-1, -1, -1):
        max_heapify(array, i, len(array))

def heap_sort(array):
    build_max_heap(array)
    for l in range(len(array), 1, -1):
        temp = array[0]
        array[0] = array[l-1]
        array[l-1] = temp
        max_heapify(array, 0, l-1)



def main():
    for n in range(100):
    #test_array = [60, 32, 16, 57, 31, 35, 31, 47, 32]
        test_array = [randrange(0,1000) for n in range(100)]
        #print(test_array)
        sorted_array = merge_sort(test_array)
        #print(sorted_array)
        if test_sorted_array(sorted_array) == False:
            print('error')
            break
    else:
        print('good')

if __name__ == "__main__":
    main()