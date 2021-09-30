int calculateSquare(int num)
{
    //    Write your code here.
    num = abs(num);
    if (num < 2)
    {
        return num;
    }

    int temp = num >> 1;

    if (num & 1)
    {
        return ((calculateSquare(temp) << 2) + (temp << 2) + 1);
    }
    else
    {
        return (calculateSquare(temp) << 2);
    }
}