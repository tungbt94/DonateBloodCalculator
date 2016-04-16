//tinh ngay hien mau: nhap ngay hien mau cuoi cung -> tinh ngay tiep theo co the hien mau (84 ngay sau)
#include<stdio.h>
#define SONGAYTOITHIEU 84
int kiemTraNamNhuan(int nam){
	if((nam % 4 == 0) && (nam % 100 != 0) || (nam % 400 == 0))
		return 1;
	return 0;
}
int tinhNgayCuaThang(int thang,int nam){
	switch (thang){
		case 2:
			if(kiemTraNamNhuan(nam) == 1)
				return 29;
			return 28;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
			break;
		default:
			return 30;	
	}
}

/*
*nhap nam
*1994 <= nam  <= 2016
*/
void nhapNam(int &nam){
	printf("Nhap nam: ");
	scanf("%d", &nam);
	while(nam < 1994 || nam > 2016){
		printf("Nhap nam tu 1994 den 2016: ");
		scanf("%d", &nam);
	}
}
/*
* nhap thang
* thang tu 1 den 12
*/
void nhapThang(int &thang){
	printf("Nhap thang: ");
	scanf("%d", &thang);
	while(thang < 1 || thang > 12){
		printf("Nhap thang tu 1 den 12: ");
		scanf("%d", &thang);
	}
}

/*
* nhap ngay
* dua vao thang de kiem tra ngay
*/
void nhapNgay(int &ngay, int &thang, int &nam){
	printf("Nhap ngay: ");
	scanf("%d", &ngay);
	int ngayCuoiThang = tinhNgayCuaThang(thang, nam);
	while(ngay < 1 || ngay > ngayCuoiThang){
		printf("Nhap ngay tu 1 ngay den %d: ", ngayCuoiThang);
		scanf("%d", &ngay);
	}
}
	
void nhap(int &ngay, int &thang, int &nam){
	printf("Nhap thong tin ngay hien mau: \n");
	nhapNam(nam);
	nhapThang(thang);
	nhapNgay(ngay,thang,nam);
}

//chinh lai thang neu thang = 13
void suaThang(int &thang, int &nam){
	if(thang > 12){
		thang = thang - 12;
		nam ++;
	}
}

/* 	tinh ngay hien mau cach 1
*	xet ngay
*	gia su so ngay toi thieu = 90, tat ca cac thang co 30 ngay thi ngay hien mau giu nguyen
*	thuc te: ngay toi thieu = 84, cac thang co so ngay khac nhau
*	Ta se lay ngay - 6 va cong chenh lech giua ngay cuoi cac thang voi 30
*/
void tinhNgayHienMau2(int &ngay, int &thang, int &nam){	
	//tru ngay di 6
	if(ngay >= 7){
		ngay -= 6;
	}else {
		thang -= 1;
		ngay = ngay - 6 + tinhNgayCuaThang(thang, nam);
	}
	
	//cong chenh lech thang
	for( int i = 0; i < 3; i++){
		//kiem tra thang
		suaThang(thang,nam);
		//cong chenh lech ngay
		ngay += 30 - tinhNgayCuaThang(thang, nam);
		thang ++;
	}
	//kiem tra thang lan cuoi
	suaThang(thang,nam);
}

/*	tinh ngay hien mau cach 2
*	tru ngay toi thieu di so ngay hien tai den cuoi thang con bao nhieu ngay
*	tru so ngay 2 thang tiep
*	gan so ngay con lai (so ngay toi thieu) cho thang thu 3
*/
void tinhNgayHienMau1(int &ngay, int &thang, int &nam){
	//khai bao bien tam = SONGAYTOITHIEU
	int temp = SONGAYTOITHIEU;
	//tru ngay toi thieu di so ngay hien tai den cuoi thang con bao nhieu ngay
	temp -= tinhNgayCuaThang(thang, nam) - ngay;
	//tru so ngay 2 thang tiep
	thang ++;
	suaThang(thang,nam);
	temp -= tinhNgayCuaThang(thang, nam);
	thang ++;
	suaThang(thang,nam);
	temp -= tinhNgayCuaThang(thang, nam);
	//gan so ngay con lai (so ngay toi thieu) cho thang thu 3
	thang ++;
	ngay = temp;
}

void inKetQua(int &ngay, int &thang, int &nam){
	printf("Ngay hien mau tiep:\n %d %d %d", ngay, thang, nam);
}
int main(){
	int ngay, thang, nam;
	nhap(ngay, thang, nam);
	tinhNgayHienMau1(ngay, thang, nam);
	inKetQua(ngay, thang, nam);
}
