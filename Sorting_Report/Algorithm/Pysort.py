import numpy
import time

# Đọc file lấy mảng
with open("C:\\Users\\cuong\\Dropbox\\DSA_UIT\\Sorting_Report\\testcase\\testcase1.txt", "r") as f:
    data = f.read().split("\n")
    arr = [float(x) for x in data]
# Bấm giờ
start = time.time()
arr = numpy.sort(arr)
end = time.time()
# Tính giờ
sec = end - start
print(sec * 1000, "ms")
