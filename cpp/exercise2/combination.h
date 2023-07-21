#include <stdio.h>

class Combination {
public:
	void all(int A[]) {
		int n = 16;
		const int m = 7;
		int arr[m];
		int idx[m];
		int cnt = 0;

		for(int i = 0; i < m; i++) {
			arr[i] = A[i];
			idx[i] = i;
		}

		while(true) {
			for(int i = 0; i < m; i++)
				printf("%d ", arr[i]);
			cnt++;
			puts("");


			int i = m - 1;
			for(; i >= 0 && idx[i] == n - m + i; i--);

			if(i < 0)
				break;

			idx[i]++;

			for(int j = i + 1; j < m; j++)
				idx[j] = idx[j - 1] + 1;

			for(int j = 0; j < m; j++)
				arr[j] = A[idx[j]];
		}
		printf("Á¶ÇÕ ¼ö : %d\n", cnt);
		
	}
};
