#include <iostream>
using namespace std;
int YearToCentury(short year)
{
    short century;
    __asm
    {
        mov ax, year
        mov bx, 100
        mov dx, 0
        div bx
        cmp dx, 0

        jne plus_one
        jmp end_

        plus_one :
        inc ax

            end_ :
        mov century, ax
    }
    return century;
}
int main()
{
    short year;
    cout << "Enter year:";
    cin >> year;
    if (year <= 0)
    {
        cout << "Error! Invalid year input!\n";
        return 0;
    }
    cout << "Century - " << YearToCentury(year);
    return 0;
}