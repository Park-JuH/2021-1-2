#include <stdio.h>

struct {
	char companyName[20];
	float stockEarningsPerShare;
	float priceToEarningsRatio;
}stockPrice;

void main()
{
	scanf("%s", &stockPrice.companyName);
	scanf(" %f", &stockPrice.stockEarningsPerShare);
	scanf("%f", &stockPrice.priceToEarningsRatio);
	printf("CompanyName: %s\nstock price: %f\n\n", stockPrice.companyName, (double)stockPrice.stockEarningsPerShare * (double)stockPrice.priceToEarningsRatio);

	scanf("%s", &stockPrice.companyName);
	scanf(" %f", &stockPrice.stockEarningsPerShare);
	scanf("%f", &stockPrice.priceToEarningsRatio);
	printf("CompanyName: %s\nstock price: %f\n\n", stockPrice.companyName, (double)stockPrice.stockEarningsPerShare * (double)stockPrice.priceToEarningsRatio);

	scanf("%s", &stockPrice.companyName);
	scanf(" %f", &stockPrice.stockEarningsPerShare);
	scanf("%f", &stockPrice.priceToEarningsRatio);
	printf("CompanyName: %s\nstock price: %f\n\n", stockPrice.companyName, (double)stockPrice.stockEarningsPerShare * (double)stockPrice.priceToEarningsRatio);

	scanf("%s", &stockPrice.companyName);
	scanf(" %f", &stockPrice.stockEarningsPerShare);
	scanf("%f", &stockPrice.priceToEarningsRatio);
	printf("CompanyName: %s\nstock price: %f\n\n", stockPrice.companyName, (double)stockPrice.stockEarningsPerShare * (double)stockPrice.priceToEarningsRatio);

	scanf("%s", &stockPrice.companyName);
	scanf(" %f", &stockPrice.stockEarningsPerShare);
	scanf("%f", &stockPrice.priceToEarningsRatio);
	printf("CompanyName: %s\nstock price: %f\n\n", stockPrice.companyName, (double)stockPrice.stockEarningsPerShare * (double)stockPrice.priceToEarningsRatio);

}