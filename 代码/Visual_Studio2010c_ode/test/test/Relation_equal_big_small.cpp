#include"Relation.h"
#include "stdafx.h"
void Relation_ship::get_Ia(string s)
{
	first="";
	second="";
	for(unsigned i=0;i<s.size();i++){
		for(unsigned j=0;j<s.size();j++){//关系判断 
			if(s[i]==s[j]){
				this->first+=s[i];
				this->second+=s[j];
			}
		}
	}
}
void Relation_ship::get_Bigger(string s)
{
	first="";
	second="";
	for(unsigned i=0;i<s.size();i++){
		for(unsigned j=0;j<s.size();j++){//关系判断 
			if(s[i]>s[j]){
				this->first+=s[i];
				this->second+=s[j];
			}
		}
	}
}
void Relation_ship::get_Smaller(string s)
{
	first="";
	second="";
	for(unsigned i=0;i<s.size();i++){
		for(unsigned j=0;j<s.size();j++){//关系判断 
			if(s[i]<s[j]){
				this->first+=s[i];
				this->second+=s[j];
			}
		}
	}
	//cout<<toRelaString()<<endl;
 } 

