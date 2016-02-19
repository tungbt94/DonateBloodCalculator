//tinh ngay hien mau
#include<stdio.h>
#include<stdlib.h>
unsigned int ngay, thang, nam;
int ktNamNhuan(int namCanTim){
	if((namCanTim % 4 == 0) && (namCanTim % 100 != 0) || (namCanTim % 400 == 0))
		return true;
	return false;
}
int tinhNgayCuoiThang(int thangCanTim, int namCanTim){
	switch (thangCanTim){
		case 2:
			if(ktNamNhuan(namCanTim) == 1)
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
void nhap(){
	printf("Nhap thong tin ngay hien mau \n");
	/*
	* nhap nam
	* nam nam trong khoang 1994(nam ra doi) den 2016 (nam hien tai)
	*/
	printf("Nhap nam: ");
	scanf("%d",&nam);
	while(nam < 2000 || nam > 2016){
		printf("Nhap nam tu 2000 den 2016: ");
		scanf("%d",&nam);
	}

	/*
	* nhap thang
	* thang tu 1 den 12
	*/
	printf("Nhap thang: ");
	scanf("%d",&thang);
	while(thang < 1 || thang > 12){
		printf("Nhap thang tu 1 den 12: ");
		scanf("%d",thang);
	}
	
	/*
	* nhap ngay
	* dua vao thang de kiem tra ngay
	*/
	printf("Nhap ngay: ");
	scanf("%d",&ngay);
	int ngayCuoiThang = tinhNgayCuoiThang(thang, nam);
	while(ngay < 1 || ngay > ngayCuoiThang){
		printf("Nhap ngay tu 1 den %d ",ngayCuoiThang);
		scanf("%d",&ngay);
	}
}
void tinhNgay(){
	int soNgayToiThieu = 84;
	//xet thang: thang = 12 thi set
	/*
	*	xet ngay
	*	gia su so ngay toi thieu = 90, tat ca cac thang co 30 ngay thi ngay hien mau giu nguyen
	*	thuc te: ngay toi thieu = 84, cac thang co so ngay khac nhau
	*	Ta se lay ngay - 6 va cong chenh lech giua ngay cuoi cac thang voi 30
	*/
	//tru ngay di 6
	if(ngay > 7)
		ngay -= 6;
	else{
		thang -= 1;
		ngay = ngay - 6 + tinhNgayCuoiThang(thang, nam);
	}
	//cong chenh lech thang
	for(int i = 0; i < 3; i++){
		//kiem tra thang
		if(thang == 13)
			thang = 1;
		//cong chenh lech ngay
		ngay += 30 - tinhNgayCuoiThang(thang, nam);
//		printf("qua thang %d ngay la: %d \n",thang,ngay);
		thang = thang + 1;
	}
}
void inKetQua(){
	printf("Ngay hien mau tiep:\n %d %d %d", ngay, thang, nam);
}
int main(){
	nhap();
	tinhNgay();
	inKetQua();
}
