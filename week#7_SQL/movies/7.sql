-- 7. All movies and ratings from 2010, in decreasing order by rating (alphabetical for those with same ratings.

SELECT movies.title, ratings.rating FROM movies INNER JOIN ratings ON movies.id = ratings.movie_id AND movies.year = 2010 AND ratings.rating > 0 GROUP BY rating.ratings DESC, title ASC;
