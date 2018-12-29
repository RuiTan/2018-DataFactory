load data inpath '/dwh/actor.csv' overwrite into table actor;
load data inpath '/dwh/actor_act_movie.csv' overwrite into table actor_act_movie;
load data inpath '/dwh/comment.csv' overwrite into table comment;
load data inpath '/dwh/format.csv' overwrite into table format;
load data inpath '/dwh/language.csv' overwrite into table language;
load data inpath '/dwh/movie_has_format.csv' overwrite into table movie_has_format;
load data inpath '/dwh/movie_has_language.csv' overwrite into table movie_has_language;
load data inpath '/dwh/movie_has_subtitle.csv' overwrite into table movie_has_subtitle;
load data inpath '/dwh/producer.csv' overwrite into table producer;
load data inpath '/dwh/producer_produce_movie.csv' overwrite into table producer_produce_movie;
load data inpath '/dwh/studio.csv' overwrite into table studio;
load data inpath '/dwh/studio_sponsor_movie.csv' overwrite into table studio_sponsor_movie;
load data inpath '/dwh/subtitle.csv' overwrite into table subtitle;
load data inpath '/dwh/writer.csv' overwrite into table writer;
load data inpath '/dwh/writer_write_movies.csv' overwrite into table writer_write_movies;