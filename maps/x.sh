#!/bin/bash

#type="intermediate"
type="eval"

# Une seule case
./gen.pl 1 1 0 > "$type"_map_one_empty_box
./gen.pl 1 1 100 > "$type"_map_one_filled_box

# Une seule ligne >
./gen.pl 100 1 0 > "$type"_map_one_empty_line
./gen.pl 100 1 25 > "$type"_map_one_line_with_obstacles_25pc
./gen.pl 100 1 50 > "$type"_map_one_line_with_obstacles_50pc
./gen.pl 100 1 75 > "$type"_map_one_line_with_obstacles_75pc
./gen.pl 100 1 100 > "$type"_map_one_filled_line

# Une seule colonne ^
./gen.pl 1 100 0 > "$type"_map_one_empty_column
./gen.pl 1 100 25 > "$type"_map_one_column_with_obstacles_25pc
./gen.pl 1 100 50 > "$type"_map_one_column_with_obstacles_50pc
./gen.pl 1 100 75 > "$type"_map_one_column_with_obstacles_75pc
./gen.pl 1 100 100 > "$type"_map_one_filled_column

# Un rectangle long >
./gen.pl 97 21 0 > "$type"_map_97_21_empty
./gen.pl 97 21 25 > "$type"_map_97_21_with_obstacles_25pc
./gen.pl 97 21 50 > "$type"_map_97_21_with_obstacles_50pc
./gen.pl 97 21 75 > "$type"_map_97_21_with_obstacles_75pc
./gen.pl 97 21 100 > "$type"_map_97_21_filled

# Un rectangle haut ^
./gen.pl 34 137 0 > "$type"_map_34_137_empty
./gen.pl 34 137 25 > "$type"_map_34_137_with_obstacles_25pc
./gen.pl 34 137 50 > "$type"_map_34_137_with_obstacles_50pc
./gen.pl 34 137 75 > "$type"_map_34_137_with_obstacles_75pc
./gen.pl 34 137 100 > "$type"_map_34_137_filled

# Un carré
./gen.pl 187 187 0 > "$type"_map_187_187_empty
./gen.pl 187 187 25 > "$type"_map_187_187_with_obstacles_25pc
./gen.pl 187 187 50 > "$type"_map_187_187_with_obstacles_50pc
./gen.pl 187 187 75 > "$type"_map_187_187_with_obstacles_75pc
./gen.pl 187 187 100 > "$type"_map_187_187_filled

# Maps spéciales
./gen.pl 50 50 25 > "$type"_map_empty_corners # OK
sed -i 's/^o/./g' "$type"_map_empty_corners
sed -i 's/o$/./g' "$type"_map_empty_corners

./gen.pl 50 50 25 > "$type"_map_filled_corners # OK
sed -i 's/^\./o/g' "$type"_map_filled_corners
sed -i 's/\.$/o/g' "$type"_map_filled_corners

./gen.pl 50 50 100 > "$type"_map_one_empty_box_top # OK

./gen.pl 50 50 100 > "$type"_map_one_empty_box_bottom # OK

./gen.pl 50 50 100 > "$type"_map_one_empty_box_right # OK

./gen.pl 50 50 100 > "$type"_map_one_empty_box_left # OK

./gen.pl 50 50 100 > "$type"_map_one_empty_box_inside # OK

# Grande map
./gen.pl 100 100 15 > "$type"_map_100_100
./gen.pl 200 200 15 > "$type"_map_200_200
./gen.pl 500 500 15 > "$type"_map_500_500
./gen.pl 500 500 15 > "$type"_map_500_500_2
./gen.pl 500 500 15 > "$type"_map_500_500_3
./gen.pl 1000 1000 15 > "$type"_map_1000_1000
./gen.pl 1000 1000 20 > "$type"_map_1000_1000_2
./gen.pl 2000 2000 15 > "$type"_map_2000_2000
./gen.pl 5000 5000 15 > "$type"_map_5000_5000
./gen.pl 10000 10000 15 > "$type"_map_10000_10000
