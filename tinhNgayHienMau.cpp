//tinh ngay hien mau: nhap ngay hien mau cuoi cung -> tinh ngay tiep theo co the hien mau (84 ngay sau)
#include<stdio.h>
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

void nhap(int &ngay, int &thang, int &nam){
	printf("Nhap thong tin ngay hien mau: \n");
	/*
	*nhap nam
	*1994 <= nam  <= 2016
	*/
	printf("Nhap nam: ");
	scanf("%d", &nam);
	while(nam < 1994 || nam > 2016){
		printf("Nhap nam tu 1994 den 2016: ");
		scanf("%d", &nam);
	}
	
	/*
	* nhap thang
	* thang tu 1 den 12
	*/
	printf("Nhap thang: ");
	scanf("%d", &thang);
	while(thang < 1 || thang > 12){
		printf("Nhap thang tu 1 den 12: ");
		scanf("%d", &thang);
	}
	
	/*
	* nhap ngay
	* dua vao thang de kiem tra ngay
	*/
	printf("Nhap ngay: ");
	scanf("%d", &ngay);
	int ngayCuoiThang = tinhNgayCuaThang(thang, nam);
	while(ngay < 1 || ngay > ngayCuoiThang){
		printf("Nhap ngay tu 1 ngay den %d: ", ngayCuoiThang);
		scanf("%d", &ngay);
	}
}

void tinhNgayHienMau(int &ngay, int &thang, int &nam){
	int soNgayToiThieu = 84;
	/*
	*	xet ngay
	*	gia su so ngay toi thieu = 90, tat ca cac thang co 30 ngay thi ngay hien mau giu nguyen
	*	thuc te: ngay toi thieu = 84, cac thang co so ngay khac nhau
	*	Ta se lay ngay - 6 va cong chenh lech giua ngay cuoi cac thang voi 30
	*/
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
		if(thang > 12){
			thang = thang - 12;
			nam ++;
		}
		//cong chenh lech ngay
		ngay += 30 - tinhNgayCuaThang(thang, nam);
		thang ++;
	}
}

void inKetQua(int &ngay, int &thang, int &nam){
	printf("Ngay hien mau tiep:\n %d %d %d", ngay, thang, nam);
}
int main(){
	int ngay, thang, nam;
	nhap(ngay, thang, nam);
	tinhNgayHienMau(ngay, thang, nam);
	inKetQua(ngay, thang, nam);
}
