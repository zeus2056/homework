#include <stdio.h>
int Kontrol();
int main() {
    char matrix[4][4] = 
    {
        {'D', 'R', 'D', 'L'}, 
        {'L', 'L', 'D', 'R'}, 
        {'D', 'L', 'L', 'R'}, 
        {'R', 'R', 'R', 'D'}
    };
    //matrisin satir veya sutun boyutu .....
    int matrix_col_lenght = 4,matrix_line_lenght=4;
    int sonuc =Kontrol(matrix,matrix_col_lenght,matrix_line_lenght);
    printf("SONUC : %d",sonuc);
    return 0;
}
int Kontrol(char matrix[4][4],int matrix_col_lenght,int matrix_line_lenght)
{
    int i = 0,j = 0,finish =0,n=0;
    int dr=1,ul=-1;
    while(1)
    {
        while(1)
        {
            char tutucu = matrix[i][j];
            if(i == 3)
            {
                if(tutucu == 'D')
                {
                    ++finish;
                    break;
                }
                else if(tutucu == 'U')i += ul;
                if(tutucu == 'R' && i == 3)
                {
                    ++finish;
                    break;
                }
                else if(tutucu == 'R ') j += dr;
                if(tutucu == 'L' && j == 0) {
                    ++finish;
                    break;
                }
                else j += ul;
            }
            else
            {
                if(tutucu == 'D') i +=dr;
                else if(tutucu == 'U') i+=ul;
                else if(tutucu == 'R') j+=dr;
                else if(tutucu == 'L') j+=ul;
            }
            if(i>3 || j<0) {
                ++n;
                break;
            }
        }
        i = 0;j=n;
        if(finish != 0)return 1;
        if(j == 4) return 0;
    }
}