class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        snake.push_front(make_pair(0,0));
        occupy.assign(height, vector<bool>(width, 0));
        occupy[0][0]=1;
        this->width=width;
        this->height=height;
        this->food=food;
        foodIndex=0;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pair<int, int> pos=snake.front();
        pair<int, int> back=snake.back();
        occupy[back.first][back.second]=0;
        snake.pop_back();
        
        
        
        if(direction=="U") pos.first--; 
        else if (direction=="L") pos.second--;  
        else if (direction=="R") pos.second++;
        else if (direction=="D") pos.first++;
        
        if(pos.first<0 || pos.first>=height || pos.second<0 || pos.second>=width) return -1;
        if(occupy[pos.first][pos.second]==1) return -1;
        
        snake.push_front(pos);
        occupy[pos.first][pos.second]=1;
        
        if(foodIndex>=food.size()) return snake.size()-1;
        if(pos==food[foodIndex]) {
            foodIndex++;
            occupy[back.first][back.second]=1;
            snake.push_back(back);
        }
        
        return snake.size()-1;
    }
private:
    deque<pair<int, int>> snake;
    vector<vector<bool>> occupy;
    int width;
    int height;
    vector<pair<int, int>> food;
    int foodIndex;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */