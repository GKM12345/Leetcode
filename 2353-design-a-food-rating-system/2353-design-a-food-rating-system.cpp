struct compare
{
    bool operator()(const pair<int, string> &x, const pair<int, string> &y) const
    {
        if (x.first == y.first)
        {
            return x.second > y.second;
        }
        return x.first < y.first;
    }
};

class FoodRatings {
    
    map<string,string> foodplace;
    map<string,set<pair<int,string>,compare>> plratfood;
    map<string,int> foorat;
    
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        int n=foods.size();
        for(int i=0;i<n;i++)
        {
            foodplace.insert({foods[i],cuisines[i]});
            plratfood[cuisines[i]].insert({ratings[i],foods[i]});
            foorat.insert({foods[i],ratings[i]});
        }
        
    }
    
    void changeRating(string food, int newRating) {
        
        
        string place=foodplace[food];
        
        int rat=foorat[food];
        foorat.erase(food);
        foorat.insert({food,newRating});
        
        plratfood[place].erase({rat,food});
        plratfood[place].insert({newRating,food});
        
        
    }
    
    string highestRated(string cuisine) {
        
        auto ans=(plratfood[cuisine].rbegin());
        return ans->second;
        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */