#include <stdio.h>

int main() {
    printf("REAL NUMBER STORAGE VAULT v1.0\n\n");

    int nsize;
    printf("[QST] How many real numbers would you like to store? : "); scanf("%d", &nsize);
    float tab[nsize];

    for(int i = 0; i < nsize; i++) {
        printf("Tab[%d] = ", i+1); 
        scanf("%f", &tab[i]);
    }

    printf("[INF] You provided %d values. The table contain followin data:\n", nsize);
    float sumy = 0, sumx = 0;
    int min = 0, max = 0;

    for(int i = 0; i < nsize; i++) {
        printf(" Tab[%d] = %f\n", i+1, tab[i]);
        if(tab[i] < tab[min]) min = i;
        else if(tab[i] > tab[max]) max = i;
        sumy += tab[i];
        sumx += i+1;

    }
    printf("[INF] In reverse order:\n");

    for(int i = nsize; i > 0; i--) {
        printf(" Tab[%d] = %f\n", i, tab[i-1]);
    }

    float meany = sumy/nsize;
    float meanx = sumx/nsize;
    printf("[INF] Mean - arithmetic average value: %f \n", meany);

    printf("[INF] Extremes: \n");
    printf(" - maximum: Tab[%d] = %f\n", max+1, tab[max]);
    printf(" - minimum: Tab[%d] = %f\n", min+1, tab[min]);

    // Calculating slope of line of best fit: mslope = Σ((Xi-meanX)*(Yi-meanY)) / Σ((Xi-meanX)^2)
    float mnumer = 0, mdenom = 0;
    for(int i = 0; i < nsize; i++) {
        mnumer += (i+1-meanx) * (tab[i]-meany);
        mdenom += (i+1-meanx) * (i+1-meanx);
    }
    // Slope of line of best fit;
    float mslope = mnumer/mdenom; 

    // yintercept -> b in y=a*x+b
    float yintercept = meany - (mslope * meanx);

    // Mean Square Error formula = (1/n) * Σ(actual – forecast)^2;
    // msum -> Σ(actual – forecast)^2;
    float msesum = 0;
    for(int i = 0; i < nsize; i++) {
        msesum += (tab[i] - (((i+1)*mslope)+yintercept))*(tab[i] - (((i+1)*mslope)+yintercept));
        // DEBUGING nr 1:
        // printf("x: %d, actual: %f, forecast: %f, msesum: %f \n", i+1, tab[i], ((i+1)*mslope)+yintercept, msesum);
    }
    float mse = msesum / nsize;
    printf("[INF] Mean Squared Error (population variance): %f\n", mse);
    // DEBUGING nr 2:
    // printf("meanx = %f\n", meanx);
    // printf("meany = %f\n", meany);
    // printf("sumx = %f\n", sumx);
    // printf("sumy = %f\n", sumy);
    // printf("mslope = %f\n", mslope);
    // printf("yintercept = %f\n", yintercept);
    // printf("msesum = %f\n", msesum);
    



	return 0;
}
