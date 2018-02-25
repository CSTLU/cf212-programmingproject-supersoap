#include<iostream>

using namespace std;

int matran[10][10], diquaroi[10], n, cost = 0;

void takeInput()
{
	int i, j;

	cout << "So thanh pho: ";
	cin >> n;

	cout << "\nDien do dai duong di\n";

	for (i = 0; i < n; i++)
	{
		cout << "\nQuang duong tu thanh pho " << i + 1 << " den cac thanh pho con lai: \n";

		for (j = 0; j < n; j++)
			cin >> matran[i][j];

		diquaroi[i] = 0;
	}

	cout << "\n\nMa tran bieu thi quang duong cua cac thanh pho voi nhau:";

	for (i = 0; i < n; i++)
	{
		cout << "\n";

		for (j = 0; j < n; j++)
			cout << "\t" << matran[i][j];
	}
}

int nextcity(int c)
{
	int i, nc = 999;
	int min = 999, kmin;

	for (i = 0; i < n; i++)
	{
		if ((matran[c][i] != 0) && (diquaroi[i] == 0)) // khi và chỉ khi quãng đường từ thành phố hiện tại khác 0 đồng thời điểm đó chưa được duyêt
		{
			if (matran[c][i]  < min)
			{
				min = matran[c][i];
				kmin = matran[c][i];
				nc = i;
			}
		}
	}

	if (min != 999)
		cost = cost + kmin;

	return nc;
}

void min(int city)
{
	int i, ncity;

	diquaroi[city] = 1; //đánh dấu là thành phố này đã đi qua rồi

	cout << city + 1 << "--->";
	ncity = nextcity(city);

	if (ncity == 999)
	{
		ncity = 0;
		cout << ncity + 1;
		cost = cost + matran[city][ncity];

		return;
	}

	min(ncity);
}

int main()
{
	takeInput();

	cout << "\n\nLoi di ngan nhat :\n";
	min(0); // chuyền vào thành phố đầu tiên nơi mà người thương nhân đứng tức là thành phố 0

	cout << "\n\nDo dai cua quang duong ngan nhat: " << cost << endl;
	system("pause");
	return 0;
	
}