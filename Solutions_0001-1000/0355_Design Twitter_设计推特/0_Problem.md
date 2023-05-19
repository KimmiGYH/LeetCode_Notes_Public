# [355. Design Twitter](https://leetcode.com/problems/design-twitter/) (Medium)



Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the `10` most recent tweets in the user's news feed.

Implement the `Twitter` class:

- `Twitter()` Initializes your twitter object.
- `void postTweet(int userId, int tweetId)` Composes a new tweet with ID `tweetId` by the user `userId`. Each call to this function will be made with a unique `tweetId`.
- `List<Integer> getNewsFeed(int userId)` Retrieves the `10` most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be **ordered from most recent to least recent**.
- `void follow(int followerId, int followeeId)` The user with ID `followerId` started following the user with ID `followeeId`.
- `void unfollow(int followerId, int followeeId)` The user with ID `followerId` started unfollowing the user with ID `followeeId`.

 

**Example 1:**

```
Input
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

Explanation
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
```

 

**Constraints:**

- `1 <= userId, followerId, followeeId <= 500`
- `0 <= tweetId <= 10^4`
- All the tweets have **unique** IDs.
- At most `3 * 10^4` calls will be made to `postTweet`, `getNewsFeed`, `follow`, and `unfollow`.



# [355. 设计推特](https://leetcode-cn.com/problems/design-twitter/)

难度中等

设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近 `10` 条推文。

实现 `Twitter` 类：

- `Twitter()` 初始化简易版推特对象
- `void postTweet(int userId, int tweetId)` 根据给定的 `tweetId` 和 `userId` 创建一条新推文。每次调用此函数都会使用一个不同的 `tweetId` 。
- `List<Integer> getNewsFeed(int userId)` 检索当前用户新闻推送中最近 `10` 条推文的 ID 。新闻推送中的每一项都必须是由用户关注的人或者是用户自己发布的推文。推文必须 **按照时间顺序由最近到最远排序** 。
- `void follow(int followerId, int followeeId)` ID 为 `followerId` 的用户开始关注 ID 为 `followeeId` 的用户。
- `void unfollow(int followerId, int followeeId)` ID 为 `followerId` 的用户不再关注 ID 为 `followeeId` 的用户。

 

**示例：**

```
输入
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
输出
[null, null, [5], null, null, [6, 5], null, [5]]

解释
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // 用户 1 发送了一条新推文 (用户 id = 1, 推文 id = 5)
twitter.getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含一个 id 为 5 的推文
twitter.follow(1, 2);    // 用户 1 关注了用户 2
twitter.postTweet(2, 6); // 用户 2 发送了一个新推文 (推文 id = 6)
twitter.getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含两个推文，id 分别为 -> [6, 5] 。推文 id 6 应当在推文 id 5 之前，因为它是在 5 之后发送的
twitter.unfollow(1, 2);  // 用户 1 取消关注了用户 2
twitter.getNewsFeed(1);  // 用户 1 获取推文应当返回一个列表，其中包含一个 id 为 5 的推文。因为用户 1 已经不再关注用户 2
```

 

**提示：**

- `1 <= userId, followerId, followeeId <= 500`
- `0 <= tweetId <= 10^4`
- 所有推特的 ID 都互不相同
- `postTweet`、`getNewsFeed`、`follow` 和 `unfollow` 方法最多调用 `3 * 10^4` 次