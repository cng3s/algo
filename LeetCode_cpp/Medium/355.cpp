// 执行用时 :176 ms, 在所有 C++ 提交中击败了11.86% 的用户
// 内存消耗 :23.6 MB, 在所有 C++ 提交中击败了33.33%的用户

class Twitter {
private:
    typedef struct _user {
        map<int, bool> followees;
        map<int, bool> followers;
        map<unsigned long long, int> tweets; // map< post_time, tweetId >
    } _user;

    unordered_map<int, _user> _id_user;
    unsigned long long _time; // 时间计数器

public:
    /** Initialize your data structure here. */
    Twitter() : _time(0) {
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        auto userIt = _id_user.find( userId );
        if ( userIt == _id_user.end() ) {
            _user newUser;
            _id_user.insert( {userId, newUser} );
            userIt = _id_user.find( userId );
        }
        // 更新自己的推文
        auto& tweets = userIt->second.tweets;
        tweets.insert( {_time++, tweetId} );
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. 
    Each item in the news feed must be posted by users who the user followed or by the user herself. 
    Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        auto userIt = _id_user.find( userId );
        vector<int> ans;
        map<unsigned long long, int, greater<unsigned long long>> time_tweet;

        if ( userIt == _id_user.end() ) { return ans; }

        const auto& mytweets = userIt->second.tweets;
        for ( const auto& tweet : mytweets ) { time_tweet.insert( {tweet.first, tweet.second} ); }

        const auto& followees = userIt->second.followees;
        for ( const auto& followee : followees ) {
            const auto& tweets = _id_user.find( followee.first )->second.tweets;
            for ( const auto& tweet : tweets ) { time_tweet.insert( {tweet.first, tweet.second} ); }
        }

        int cnt = 0;
        for ( const auto& it : time_tweet ) {
            if ( cnt == 10 ) { break; }
            ans.push_back( it.second );
            ++cnt;
        }

        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        auto followerIter = _id_user.find( followerId ), followeeIter = _id_user.find( followeeId );
        // 1. 如果找不到用户，则注册它
        if ( followerIter == _id_user.end() ) {
            _user newUser;
            _id_user.insert( {followerId, newUser} );
            followerIter = _id_user.find( followerId );
        }
        if ( followeeIter == _id_user.end() ) {
            _user newUser;
            _id_user.insert( {followeeId, newUser} );
            followeeIter = _id_user.find( followeeId );
        }

        // 2. 如果 follower 已经关注了 followee，则返回; 否则，插入 followeeId
        //    插入 followeeId 还要插入推文到其他用户的最新推文表中
        auto& followeesList = followerIter->second.followees;
        if ( followeesList.find( followeeId ) == followeesList.end() ) {
            followeesList.insert( {followeeId, true} );
        }

    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        auto followIt = _id_user.find( followerId );
        if ( followIt == _id_user.end() ) { return ; }
        auto& followees = followIt->second.followees;
        auto resIt = followees.find( followeeId );

        // 如果 follower 没有关注 followee，则直接返回；否则，删除 followee
        if ( resIt != followees.end() ) {
            followees.erase( resIt );
        }

    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */