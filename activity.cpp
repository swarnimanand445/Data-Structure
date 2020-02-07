#include<bits/stdc++.h>
using namespace std;
struct activity
{
	int s;
	int f;
};
bool cmp(activity a,activity b)
{
	return a.f>b.f;
}
void printMaxActivities( activity s[], activity f[],int n) 
{ 
	sort(f,f+n,cmp);
    int i, j; 
  
    printf ("Following activities are selected n"); 
  
    // The first activity always gets selected 
    i = 0; 
    printf("%d ", i); 
  
    // Consider rest of the activities 
    for (j = 1; j < n; j++) 
    { 
      // If this activity has start time greater than or 
      // equal to the finish time of previously selected 
      // activity, then select it 
      if (s[j] >= f[i]) 
      { 
          printf ("%d ", j); 
          i = j; 
      } 
    } 
} 
  
// driver program to test above function 
int main() 
{ 
	int s[10],f[10],n;
  	cin>>n;
  	for(int i=0;i<n;i++)
  	cin>>s[i];
  	for(int i=0;i<n;i++)
  	cin>>f[i];
    printMaxActivities(s, f, n); 
    return 0; 
} 
