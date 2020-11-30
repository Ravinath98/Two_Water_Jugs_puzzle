#include <iostream>


using namespace std;

int getGCD(int a, int b) {  //fuction to calculate Greatest Common Divisor of a and b...

    int remainAB = b % a;   //remainder value b,a...

    if (remainAB != 0)
    {
        b = a;
        a = remainAB;
        getGCD(a, b);       //recursively call the getGCD(a,b) function...

    }
    else
    {
        return a;           //this returns 'a' means the GCD of a and b...
    }



}

//if b>a....
int waterJugs(int tempA, int tempB, int tempC, int x, int y, int c)  //this function to output the steps when obtain exactly c litre from jugs...
{
    if (y != c)
    {

        if (x != 0)
        {
            cout << "(" << x << "," << y << ")" << " > ";
            y = x + y;
            if (y >= tempB)         //when b jug full or over full..
            {
                x = y - tempB;
                y = tempB;
            }
            else
            {
                x = 0;
            }
            if (y == tempC)
            {
                cout << "(" << x << "," << y << ")";
            }
            else
            {
                cout << "(" << x << "," << y << ")" << " > ";
            }
            if (y == tempB)         //when b jug full exactly.. 
            {
                y = 0;
                cout << "(" << x << "," << y << ")" << " > ";
                y = x;
                x = 0;
            	if (y == tempC)
            	{
                	cout << "(" << x << "," << y << ")";
            	}
            	else
            	{
                	cout << "(" << x << "," << y << ")" << " > ";
            	}
            }
            waterJugs(tempA, tempB, tempC, x, y, c);    //recursively call the waterJugs() function...
        }
        else
        {
            x = tempA;
            waterJugs(tempA, tempB, tempC, x, y, c);   //recursively call the waterJugs() function...
        }
    }
    else
    {
        return 0;
    }
}

//if a>b....
int waterJugs1(int tempA, int tempB, int tempC, int x, int y, int c)  //this function to output the steps when obtain exactly c litre from jugs...
{
    if (x != c)
    {

        if (y != 0)
        {
            cout << "(" << x << "," << y << ")" << " > ";
            x = x + y;
            if (x >= tempA)         //when a jug full or over full..
            {
                y = x - tempA;
                x = tempA;
            }
            else
            {
                y = 0;
            }
            if (x == tempC)
            {
                cout << "(" << x << "," << y << ")";
            }
            else
            {
                cout << "(" << x << "," << y << ")" << " > ";
            }
            if (x == tempA)         //when a jug full exactly.. 
            {
                x = 0;
                cout << "(" << x << "," << y << ")" << " > ";
                x = y;
                y = 0;
                if (x == tempC)
                {
                    cout << "(" << x << "," << y << ")";
                }
                else
                {
                    cout << "(" << x << "," << y << ")" << " > ";
                }
            }
            waterJugs1(tempA, tempB, tempC, x, y, c);    //recursively call the waterJugs1() function...
        }
        else
        {
            y = tempB;
            waterJugs1(tempA, tempB, tempC, x, y, c);   //recursively call the waterJugs1() function...
        }
    }
    else
    {
        return 0;
    }
}


int main()
{
    while (true)    //to enter values continuously...
    {
    	int a,b,c;   //declare a,b,c....
        
        cout<<"----Enter a,b,c Values Orderly----"<<endl;
        //inputs....
        cout<<"a : ";
        cin>>a;
        cout<<"b : ";
        cin>>b;
        cout<<"c : ";
        cin>>c;



        if (a <= 40000 && b <= 40000 && c <= 40000 && (c<=a || c<=b))		//check a,b,c values...
        {

            cout << endl;


            int value = getGCD(a, b);   //value means the GCD of a and b...
        

            if (c % value == 0)         //if this is true then we can get the exactly c litres from given jugs...
            {
                int tempA = a;
                int tempB = b;
                int tempC = c;
                //x,y are the values inside the jugs in each steps
                cout << "Steps to Get c litres: ";
                if (a < b)
                {
                    int y = 0;
                    int x = tempA;
                    cout << "(" << 0 << "," << 0 << ")" << " > ";
                    waterJugs(tempA, tempB, tempC, x, y, c);    //call the waterJugs() fuction...
                }
                else
                {
                    int x = 0;
                    int y = tempB;
                    cout << "(" << 0 << "," << 0 << ")" << " > ";
                    waterJugs1(tempA, tempB, tempC, x, y, c);    //call the waterJugs1() fuction...
                }

            }
            else
            {
                cout << -1;             //if cannot get exactly c litres from given jugs...
            }

            cout << endl << endl;

        }
        else
        {
            cout << "Error..Please Re-Enter a,b,c values..." << endl;
        }
    }

    return 0;
}
