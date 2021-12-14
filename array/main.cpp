/**
*   Date: 12/12/2021
*   Author: Nguyen Anh Do
*/

#include <iostream>
#include <string>

using namespace std;

void printArray(const int arr[], int n);
void arrayInput(int arr[], int n);
int sum(const int arr[], int n);
float avarage(const int arr[], int n);
int maxArray(const int arr[], int n);
int minArray(const int arr[], int n);
void arraySort(const int arr[], int result[], int n);
void arrayDelete(int arr[], int index, int& n);
int arrayFind(const int arr[], int key, int n);

int main() {

    // 1. Khai báo và khởi tạo mảng
    // Vd: Muốn lưu danh sách tên 50 động vật
    string animals[] = {"Dog", "Cat", "Parot"};
    

    // 2. Truy xuất đến các phần tử trong mảng
    cout << animals[0] << endl; // Truy xuất tới phần tử đầu tiên
    cout << animals[2] << endl; // Truy xuất tới phần tử cuối cùng

    // Lỗi: Truy xuất vượt quá kích thước mảng
    // cout << animals[3] << endl;


    // 3. Nhập và xuất dữ liệu trong mảng
    int numbers[50];

    int len = 0;
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> len;

    // Nhập các giá trị vào mảng
    arrayInput(numbers, len);

    // Xuất các giá trị của mảng
    cout << "------------Cac phan tu vua nhap---------------------" << endl;
    printArray(numbers, len);

    // 4. Tính tổng, trung bình giá trị các phần tử trong mảng
    cout << "\nSum: " << sum(numbers, len) << endl;
    cout << "Average: " << avarage(numbers, len) << endl;

    // 5. Tìm phần tử lớn nhất, nhỏ nhất
    cout << "Max: " << maxArray(numbers, len) << endl;
    cout << "Min: " << minArray(numbers, len) << endl;

    // 6. Tìm kiếm
    int key, index = -1;
    cout << "Nhap gia tri can tim kiem: ";
    cin >> key;

    int result_index = arrayFind(numbers, key, len);
     if (result_index == -1) {
        cout << "Khong tim thay!" << endl;
    } else {
        cout << "Tim thay tai vi tri " << result_index << endl;
    }

    // 7. Sắp xếp mảng tăng dần, giảm dần
   int sorted_array[len];
   arraySort(numbers, sorted_array, len);

   cout << "------------Mang sau khi da sap xep---------------------" << endl;
   printArray(sorted_array, len);

    // 8. Xóa phần tử ra khỏi mảng
    int delete_index;
    cout << "\nNhap gia tri muon xoa: ";
    cin >> delete_index;

    arrayDelete(numbers, delete_index, len);
    cout << "------------Mang sau khi da xoa---------------------" << endl;
    printArray(numbers, len);

    // 9. Truyền mảng vào hàm

    cout << endl;
    
    return 0;
}

// Hàm in các giá trị mảng
// Lưu ý: Khi tuyền mảng vào hàm, sẽ được truyền bằng tham chiếu (pass by reference)
void printArray(const int arr[], int n) {

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

// Hàm nhập mảng 
void arrayInput(int arr[], int n) {

    for (int i = 0; i < n; i++) {
            cout << "Nhap phan tu thu " << i << ": ";
            cin >> arr[i];
    }
}

// Hàm tính tổng
int sum(const int arr[], int n) {

    int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
    }
    
    return sum;
}

// Hàm tính trung bình
float avarage(const int arr[], int n) {

    int s = sum(arr, n);

    return (float)s / n;
}

// Hàm tìm max
int maxArray(const int arr[], int n) {

    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    return max;
}

// Hàm tìm min
int minArray(const int arr[], int n) {

    int min = arr[0];
    for (int i = 0; i < n; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }

    return min;
}

// Hàm tìm kiếm một phần tử trong mảng
int arrayFind(const int arr[], int key, int n) {

    int index = -1;
    for (int i = 0; i < n; i++) {
        if (key == arr[i]) {
            index = i;
            break;
        }
    }

    return index;
}

// Hàm sắp xếp tăng dần
void arraySort(const int arr[], int result[], int n) {

    // Sao chép các phần tử của mảng gốc sang mảng result
    for (int i = 0; i < n; i++) {
        result[i] = arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (result[j] > result[j + 1]) {
                // Hoán đổi giá trị của 2 biến
                int tmp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = tmp;
            }
        }
    }
}

// Hàm xóa một phần tử
void arrayDelete(int arr[], int key, int& n) {
    
    // Tìm vị trí của giá trị cần xóa trong mảng
    int index = arrayFind(arr, key, n);

    if (index > -1) {
        for (int i = index; i < n; i++) {
            arr[i] = arr[i + 1];
        }
        n -= 1;
    }
}