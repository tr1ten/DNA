select count(select * from reactions where reaction_type='dislike' and post_id=t.post_id) as negative_reaction_count, t.post_id from posts t group by t.post_id;
-- same for like, love, haha, wow as positive
select count(*)-negative_reaction_count
