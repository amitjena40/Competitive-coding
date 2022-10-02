#include<bits/stdc++.h>
using namespace std ;

map<int,int> value;

void answer(vector<int> x , int m  )
{
    int ans1 = -1 , ans2 = -1 ;
    
    for(int i = 0 ; i<x.size() ; i++)
    {
        int r=m-x[i] ;//remain
        if ( r!=x[i] )
        {
            if(value.count(r) && value.count(x[i]))
            {
                ans1 = x[i] ;
                ans2 = r ;
                break ;
            }
        }
        else
        {
            if(value[x[i]]>1)
                {
                ans1 = x[i] ;
                ans2 = x[i]  ;
                break ;
                }
        }
      
        
    }
set<int> s;
    for(int i =0 ;i<x.size() ;i++ )
    {
            if(x[i]==ans1 || x[i]==ans2)
                s.insert(i) ;
    }
        
        for(int i:s)
            cout<<i+1<<" ";
    
}

int main()
{
    int t,m,n;
    cin>>t ;
    while(t--)
    {
        value.clear() ;
        cin>> m ;
        cin>> n ;
        vector<int> a(n);
        for(int i =0 ; i<n ;i++)
        {
            cin>>a[i] ;
            value[a[i]]++ ;
        }
        answer(a,m) ;
        cout<<endl ;    
    }
    
}