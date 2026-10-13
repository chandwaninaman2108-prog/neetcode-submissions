
#include <bits/stdc++.h>
using namespace std;

class Tweet {
public:
    int time;
    int tweetid;

    Tweet(int t, int id) {
        time = t;
        tweetid = id;
    }
};

class user {
private:
    int userid;
    unordered_set<int> following;
    list<Tweet> tweets;

public:
    user(int id) {
        userid = id;
    }

    void addtweet(Tweet t) {
        tweets.push_front(t);
    }

    void addfollower(int followeeId) {
        following.insert(followeeId);
    }

    void removefollower(int followeeId) {
        following.erase(followeeId);
    }

    const unordered_set<int>& getFollowing() const {
        return following;
    }

    const list<Tweet>& getTweets() const {
        return tweets;
    }
};

class Twitter {
private:
    unordered_map<int, user> usermap;
    int timecounter = 0;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        if (usermap.find(userId) == usermap.end()) {
            usermap.emplace(userId, user(userId));
        }

        usermap.at(userId).addtweet(
            Tweet(++timecounter, tweetId)
        );
    }

    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> candidates;

        // If the user does not exist, the feed is empty.
        if (usermap.find(userId) == usermap.end()) {
            return {};
        }

        const auto& followed = usermap.at(userId).getFollowing();

        // Collect tweets from the user and followed users.
        for (const auto& entry : usermap) {
            int authorId = entry.first;

            if (authorId != userId &&
                followed.find(authorId) == followed.end()) {
                continue;
            }

            for (const Tweet& t : entry.second.getTweets()) {
                candidates.push_back({t.time, t.tweetid});
            }
        }

        // Sort by timestamp, newest first.
        sort(candidates.rbegin(), candidates.rend());

        vector<int> feed;
        for (const auto& p : candidates) {
            feed.push_back(p.second);

            if (feed.size() == 10) {
                break;
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (usermap.find(followerId) == usermap.end()) {
            usermap.emplace(followerId, user(followerId));
        }

        if (usermap.find(followeeId) == usermap.end()) {
            usermap.emplace(followeeId, user(followeeId));
        }

        usermap.at(followerId).addfollower(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (usermap.find(followerId) == usermap.end()) {
            return;
        }

        usermap.at(followerId).removefollower(followeeId);
    }
};
