def selectKthNum(array, k, start, end):
    if not array or k < 0 or start >= end:
        return
      
    left,right,pivot = start,end,array[start]
    
    while left < right:
        while array[right] <= pivot and left < right:
            right -= 1
        while array[left] >= pivot and left < right:
            left += 1
        if left < right:
            array[left],array[right] = array[right],array[left]
    
    array[start] = array[left]
    array[left] = pivot
    
    if left == k:
        return
    elif left < k:
        selectKthNum(array, k, left+1, end)
    else:
        selectKthNum(array, k, start, left-1)
        
if __name__ == '__main__':
    top_k = 9
    array = [0, 3, 1, 5, 4, 9, 8, 7, 2, 6]
    selectKthNum(array, top_k, 0, 9)
    print(array)
    print(array[top_k-1])
    