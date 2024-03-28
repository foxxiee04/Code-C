#include <stdio.h>


double Dansothegioi (int nam, double sodan) {

    if (nam == 2028) {
        return sodan;
    } else {

        double tile = 0.025; 
        sodan *= (1 + tile);
        return Dansothegioi(nam + 1, sodan);
    }
}

int main() {
    double Dansohientai = 8e9; 
    int namtinh = 2028;
    

    double danso2028 = Dansothegioi(2018, Dansohientai);


    printf("Dân số thế giới vào năm %d là: %.2lf tỷ người\n", namtinh, danso2028 / 1e9);

    return 0;
}
