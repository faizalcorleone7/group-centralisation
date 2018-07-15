#include<bits/stdc++.h>  //dominating set of nodes subgraph degree centrality (k-vertex maximum domination subgraph degree centrality)
using namespace std;
int max1(vector<int> v[],vector<int> &arr,int n)	//max. degree node number
{
	int d=0,m;
	for (int i=0;i<n;i++)
	{		
		if (v[i].size()>=d && arr[i]==0)
		{
			//cout<<"bada hai"<<endl;
			d=v[i].size();
			m=i;
		}
	}	
	arr[m]=1;	
	cout<<"m = "<<m<<endl;
	return m;
};
vector<int> *clean(vector<int> v[],int c,int n)	//removal of non D.S. node records
{
	for (int i=0;i<n;i++)
	{
		if (i!=c)
		{
			for (int j=0;j<v[i].size();j++)
			{
				if (v[i][j]==c)
				{
					v[i].erase(v[i].begin()+j);
					break;	
				}	
			}	
		}	
	}	
	return v;
};
/*int calcdegcen(vector<int> v[],int n)	//calculate group degree centrality 
{
	int h=0;
	vector<int> h1;
	for (int i=0;i<n;i++)
	{
		if (h<v[i].size())
		{
			h=v[i].size();
		}
		if (v[i].size()>0)
		{
			h1.push_back(i);
		}
	}
	int s=0;
	for (int i=0;i<h1.size();i++)
	{
		s=s+(h-v[h1[i]].size());
	}
	double j=(double)s;
	//cout<<"j = "<<j<<endl;
	double size1=(double)n;
	//cout<<"size1 = "<<size1<<endl;
	double k=(size1-1)*(size1-2);
	//cout<<"k = "<<k<<endl;
	cout<<"Group degree centrality = "<<j/k<<endl;
	return j/k;
};*/
void print(vector<int> v[],int n)	//print the resultant dominating set graph
{
	for (int i=0;i<n;i++)
	{
		cout<<i<<" -> ";
		for (int j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
void calc (vector<int> deg,vector<int> v[],vector<int> arr,int n)	//erasing edges from nodes that are not part of the dominating set
{		
	cout<<"Size of dominating set: "<<deg.size()<<endl;	
	for (int i=0;i<n;i++)
	{
		if (arr[i]!=1)
		{
			v[i].erase(v[i].begin(),v[i].end());
		}
	}
	//print(v,n);
	cout<<"Erase successful"<<endl;
	//return calcdegcen(v,n);
};
void m_vertexdom(vector<int> v[],vector<int> &arr,vector<int> &s,int &k,int &n)
{
	vector<int> deg;
	//cout<<max1(v,arr,n);
	int t=0;	//number of dominated vertices
	while (t<n)
	{
	t=t+1;
	int a=max1(v,arr,n);
	//cout<<"t = "<<t<<endl;
	deg.push_back(a);	
	int c=a;
	t=t+v[c].size();
	v=clean(v,c,n);	
	}
	calc(deg,v,arr,n);
	
	for (long long int i=0;i<deg.size();i++)
	{
		cout<<deg[i]<<" ";
	}
	cout<<"size of dominating set - "<<deg.size()<<endl;
	//cout<<calcdegcen(v,n);
};
int main()
{
	int n,m;
	cout<<"Enter number of nodes: ";
	cin>>n;
	cout<<"Enter number of edges: ";
	cin>>m;
	vector<int> v[n];
	for (int i=0;i<m;i++)
	{
		int s1,s2,d;
		cout<<"Enter the edge nodes: ";
		cin>>s1>>s2;
		v[s2].push_back(s1);
		v[s1].push_back(s2);
	}
	int k=0;	//number of members of dominating set
	vector<int> s;	
	vector<int> arr;	//truth value about whether node is in D.S. or not.
	for (int i=0;i<n;i++)
	{
		arr.push_back(0);
	}
	cout<<"----------------------input and initialisation done---------------"<<endl;
	m_vertexdom(v,arr,s,k,n);
	//print(v,n);
	
	return 0;
}
/*
6
7
0 1
0 4
1 2
4 5
1 4
2 5
2 3
*/
