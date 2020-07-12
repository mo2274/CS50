SELECT title, rating FROM ratings
JOIN movies ON ratings.movie_id = movies.id
WHERE year = 2010
and rating NOT LIKE "\\N"
ORDER BY rating DESC , title ASC