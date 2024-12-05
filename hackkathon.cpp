#include <stdio.h>

int kiem_tra_so_hoan_hao(int n) {
    if (n <= 1) return 0;
    int tong_uec = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            tong_uec += i;
        }
    }
    return tong_uec == n;
}


int tim_nho_thu_2(int arr[], int n) {
    int min1 = 999999, min2 = 999999; 
    for (int i = 0; i < n; i++) {
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
    }
    return min2 == 999999 ? -1 : min2;  
}

int kiem_tra_ton_tai(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return 1; 
        }
    }
    return 0;  
}


void them_phan_tu(int arr[], int *n, int x, int vi_tri) {
    if (vi_tri < 0 || vi_tri > *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    if (kiem_tra_ton_tai(arr, *n, x)) {
        printf("Phan tu da ton tai trong mang!\n");
        return;
    }

    for (int i = *n; i > vi_tri; i--) {
        arr[i] = arr[i - 1];
    }
    arr[vi_tri] = x;
    (*n)++;
}






void in_mang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d, ", i, arr[i]);
    }
    printf("\n");
}

int main() {
    int n, lua_chon;
    int arr[100];

    while (1) {
        printf("\nMENU:\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Dem so luong cac so hoan hao co trong mang\n");
        printf("4. Tim gia tri nho thu 2 trong mang\n");
        printf("5. Them mot phan tu vao vi tri ngau nhien trong mang\n");
        printf("6. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &lua_chon);

        switch (lua_chon) {
            case 1: {
                
                printf("Nhap so phan tu cua mang: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhap gia tri phan tu thu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;
            }
            case 2: {
                
                if (n > 0) {
                    for (int i = 0; i < n; i++) {
                        printf("arr[%d] = %d, ", i, arr[i]);
                    }
                    printf("\n");
                } else {
                    printf("Chua co mang nao duoc nhap!\n");
                }
                break;
            }
            case 3: {
               
                if (n > 0) {
                    int dem = 0;
                    for (int i = 0; i < n; i++) {
                        if (kiem_tra_so_hoan_hao(arr[i])) {
                            dem++;
                        }
                    }
                    printf("So luong so hoan hao trong mang: %d\n", dem);
                } else {
                    printf("Chua co mang nao duoc nhap!\n");
                }
                break;
            }
            case 4: {
                
                if (n > 1) {
                    int nho_thu_2 = tim_nho_thu_2(arr, n);
                    if (nho_thu_2 == -1) {
                        printf("Khong co gia tri nho thu 2 trong mang!\n");
                    } else {
                        printf("Gia tri nho thu 2 trong mang: %d\n", nho_thu_2);
                    }
                } else {
                    printf("Mang qua nho de tim gia tri nho thu 2!\n");
                }
                break;
            }
            case 5: {
                
                if (n < 100) {
                    int x, vi_tri;
                    printf("Nhap gia tri phan tu can them: ");
                    scanf("%d", &x);
                    printf("Nhap vi tri muon them (0 den %d): ", n);
                    scanf("%d", &vi_tri);
                    them_phan_tu(arr, &n, x, vi_tri);
                } else {
                    printf("Mang da day! Khong the them phan tu.\n");
                }
                break;
            }
            case 6: {
                printf("Thoat chuong trinh.\n");
                return 0;
            }
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
                break;
        }
    }

    return 0;
}

