#include<iostream>
#include<vector>

//This function stores red and black index for red black Guass Siedel Method
 void calIndexes(const int numGridX, const int numGridY, std::vector<int> &redIndex,std::vector<int> &blackIndex)
{
	bool toggle = false;
	int numTotGrids = numGridX*numGridY;

	if((numGridX % 2) == 1)
	{
		for(int i=0;i < numTotGrids; i+=2)
		{
			redIndex.push_back(i);
			if(i!= (numTotGrids - 1))
			blackIndex.push_back(i+1);
		}
		
	}
	else
	{	
		for(size_t i=0; i<numGridY; ++i)
		{
			toggle = !toggle;

			for(size_t j=0;j<numGridX;j+=2)
				{
					if(toggle) 
						{
							redIndex.push_back(i*numGridX +j);
							blackIndex.push_back(1+i*numGridX +j);
						}
					else       
						{
							redIndex.push_back(1+ i*numGridX +j);
							blackIndex.push_back(i*numGridX +j);
						}
				}
		}
	}

}

int main()
{

	int numGridX,numGridY;
	std::cout<<"Please Enter Grid Point in X and Y direction respectively \n";
	std::cin>>numGridX >> numGridY ;

	std::vector<int> redIndArr;
	std::vector<int> blackIndArr;
	calIndexes(numGridX,numGridY,redIndArr, blackIndArr);

	std::cout << "Red Indexs are : \n";
	for(size_t i =0; i<redIndArr.size() ; ++i)
	{
	std::cout << redIndArr[i] << "  " ;
	}

	std::cout << "\nBlack Indexs are : \n";
	for(size_t i =0; i<blackIndArr.size() ; ++i)
	{
	std::cout << blackIndArr[i] << "  " ;
	}

    std::cout<< std::endl; 

	
	return 0;
}