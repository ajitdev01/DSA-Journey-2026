class Solution
{
    public function islandPerimeter($grid)
    {
        $rows = count($grid);
        $cols = count($grid[0]);
        $perimeter = 0;

        $dr = [-1, 1, 0, 0];
        $dc = [0, 0, -1, 1];

        for ($r = 0; $r < $rows; $r++) {
            for ($c = 0; $c < $cols; $c++) {

                if ($grid[$r][$c] == 1) {

                    for ($k = 0; $k < 4; $k++) {

                        $nr = $r + $dr[$k];
                        $nc = $c + $dc[$k];

                        // Outside grid OR water
                        if (
                            $nr < 0 || $nr >= $rows ||
                            $nc < 0 || $nc >= $cols ||
                            $grid[$nr][$nc] == 0
                        ) {
                            $perimeter++;
                        }
                    }
                }
            }
        }

        return $perimeter;
    }
}