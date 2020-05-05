#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Work {
  
  int time , speed , cost;
};

bool compare(Work a,Work b) {
  if(a.time!=b.time)
  return a.time < b.time;
  else { 
    if(a.speed!=b.speed)
      return a.speed > b.speed ;
    else {
       return a.cost<b.cost;
    }
  } 
}

ll fKnapsnack(Work arr[],ll n,ll area) {
  
  sort(arr,arr+n,compare);
  
 
  
 /* for(int i=1;(i<n)&&(areaCovered>=0);i++) {
    if(arr[i].time==arr[i-1].time) {
      if(arr[i].speed==arr[i-1].speed) {
        if(arr[i].cost==arr[i-1].cost) {
          minCost += arr[i].cost;
          areaCovered -= arr[i].speed;
        }
        else {
          minCost += min(arr[i].cost,arr[i-1].cost);
          areaCovered -= arr[i].speed;
        }
        
      }
      else {
        if(arr[i].speed>arr[i-1].speed) {
          minCost += arr[i].cost;
          areaCovered -= arr[i].speed;
        }
        else {
          minCost += arr[i-1].cost;
          areaCovered -= arr[i-1].speed;
        }
        
      }
      
    }
    
    else {
      if(arr[i].time>arr[i-1].time) {
        minCost += arr[i-1].cost;
          areaCovered -= arr[i-1].speed;
      }
      else {
        minCost += arr[i].cost;
          areaCovered -= arr[i].speed;
      }
    }
    
  }*/
  ll c_speed=arr[0].time;
  ll c_units=area;
  ll c_cost=arr[0].cost;
 
  ll timeworked=0;
  ll c_index=0;
  for(int i=1;i<n;i++)
  {
    if(arr[i].speed>arr[c_index].speed)
    {
      timeworked=arr[i].time-arr[c_index].time;
      c_units=c_units-(timeworked*arr[i].speed);
      if(c_units>0)
      {
        c_index=i;
        c_cost+=arr[i].cost;
      }
      else
      {
        break;
      }
    }
  }
 return c_cost;
   // return 0;
  
}


int main()
{
    //Write your code here
    ios_base::sync_with_stdio(false);
  ll n ;
  ll area;
  cin >> n >> area;
  
  Work arr[n];
  
  for(ll i=0;i<n;i++) {
    ll t,s,c;
    cin >> t >> c >> s;
    arr[i].time = t;
    arr[i].speed = s;
    arr[i].cost = c ;
    
  }
  
  cout << fKnapsnack(arr,n,area) << endl;
  /////sort(arr,arr+n,compare);
  
  
  
    return 0;
}