/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l=0;
      int r_ex=mountainArr.length()-1;  //r_ex is the right most index of the array
        int r=r_ex;
        int m_value;
        int middle;  //middle stores the index of the Max Element
      //This While Loop is for  finding the index of the max element
	  while(l<=r)
        {
          int m=l+(r-l)/2;
          m_value=mountainArr.get(m);
          if((m<=r_ex-1)&&(m_value<mountainArr.get(m+1)))  //if the next element if bigger, then search rightwards
          {
              l=m+1;
          }
          else if((m>=1)&&(m_value<mountainArr.get(m-1)))  //if the previous element is bigger, then search leftwards
          {
              r=m-1;
          }
          else  // We have found the max element
          {
             middle=m;
              break;
          }
              
        }
		
		//This while loop is for searching the element in the left side of the moutain peak
        l=0; 
        r=middle;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            m_value=mountainArr.get(m);
              if(l==r)
              {
                  if(target!=m_value) break;
              }
             if(target==m_value)
             {
                 return m;
             }
            else if(target>m_value)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
		
		//This while loop is for searching the element in the right side of the mountain peak
        l=middle;
        r=r_ex;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            m_value=mountainArr.get(m);
            if(l==r)
            {
                if(target!=m_value) break;
            }
            if(target==m_value) return m;
            else if(target>m_value) r=m-1;
            else l=m+1;
        }
        return -1;
        
    }
};
