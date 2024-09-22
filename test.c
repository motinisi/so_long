/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:47:49 by timanish          #+#    #+#             */
/*   Updated: 2024/09/22 19:35:46 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"
# include "minilibx-linux/mlx.h"
#include <stdio.h>

int close_window(void *param)
{
    (void)param;  // 使用しない引数
    printf("ウィンドウを閉じました。\n");
    exit(0);  // 正常終了
}

int main(void)
{
    void *mlx;         // MiniLibXの初期化用ポインタ
    void *win;         // ウィンドウのポインタ
    void *img;         // 画像のポインタ
    int img_width = 64; // 画像の幅
    int img_height = 64; // 画像の高さ

    // MiniLibXを初期化
    mlx = mlx_init();
    if (!mlx)
    {
        printf("MiniLibXの初期化に失敗しました。\n");
        return (EXIT_FAILURE);
    }

    // ウィンドウを作成 (幅800, 高さ600, タイトルは "Hello MLX")
    win = mlx_new_window(mlx, 1000, 600, "Hello MLX");
    if (!win)
    {
        printf("ウィンドウの作成に失敗しました。\n");
        return (EXIT_FAILURE);
    }

    // 画像（XPMファイル）を読み込み
    // printf("使用するファイルパス: %s\n", "images.xpm");
    img = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", &img_width, &img_height);
    if (!img)
    {
        printf("画像の読み込みに失敗しました。\n");
        return (EXIT_FAILURE);
    }

    // // 画像をウィンドウに表示 (表示位置: x = 100, y = 100)
    mlx_put_image_to_window(mlx, win, img, 999, 599);

    mlx_hook(win, 17, 0, close_window, NULL);

    // イベントループ（ウィンドウが閉じられるまで待機）
    mlx_loop(mlx);

    return (0);
}

// #include <mlx.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>
// #include <unistd.h>

// #define TILE_SIZE 32

// typedef struct s_game
// {
// 	void	*mlx;
// 	void	*win;
// 	void	*wall_img;
// 	void	*player_img;
// 	int		width;
// 	int		height;
// }	t_game;

// // マップファイルの読み込み
// char	**read_map(const char *filename)
// {
// 	int		fd;
// 	char	**map;
// 	char	*line;
// 	char	buffer[1];
// 	int		i = 0;
// 	int		j = 0;

// 	fd = open(filename, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Failed to open map file\n");
// 		return (NULL);
// 	}

// 	map = (char **)malloc(sizeof(char *) * 100); // 仮の行数（最大100行）
// 	if (!map)
// 		return (NULL);

// 	line = (char *)malloc(1024); // 仮の行サイズ
// 	if (!line)
// 		return (NULL);

// 	while (read(fd, buffer, 1) > 0)
// 	{
// 		if (buffer[0] == '\n')  // 行の終わり
// 		{
// 			line[j] = '\0';  // 行の終端を設定
// 			map[i] = line;   // 1行をマップに保存
// 			i++;
// 			line = (char *)malloc(1024);  // 次の行のために新しいメモリを確保
// 			j = 0;  // 行のインデックスをリセット
// 		}
// 		else
// 		{
// 			line[j] = buffer[0];  // 文字を行に追加
// 			j++;
// 		}
// 	}
// 	map[i] = NULL;  // マップの終わりにNULLを追加

// 	close(fd);  // ファイルを閉じる
// 	return (map);
// }










// マップに基づいてスプライトを描画
// void	draw_map(t_game *game, char **map)
// {
// 	int		x;
// 	int		y;

// 	y = 0;
// 	while (map[y] != NULL)
// 	{
// 		x = 0;
// 		while (map[y][x] != '\0')
// 		{
// 			if (map[y][x] == '1')  // 壁の描画
// 				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
// 			else if (map[y][x] == 'P')  // プレイヤーの描画
// 				mlx_put_image_to_window(game->mlx, game->win, game->player_img, x * TILE_SIZE, y * TILE_SIZE);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	t_game	game;
// 	char	**map;

// 	if (argc != 2)
// 	{
// 		printf("Usage: %s map.ber\n", argv[0]);
// 		return (1);
// 	}

// 	// マップの読み込み
// 	map = read_map(argv[1]);
// 	if (!map)
// 		return (1);

// 	// MLXの初期化
// 	game.mlx = mlx_init();
// 	game.win = mlx_new_window(game.mlx, 640, 480, "so_long");

// 	// スプライトの読み込み
// 	game.wall_img = mlx_xpm_file_to_image(game.mlx, "wall.xpm", &game.width, &game.height);
// 	game.player_img = mlx_xpm_file_to_image(game.mlx, "player.xpm", &game.width, &game.height);

// 	// マップのスプライト描画
// 	draw_map(&game, map);

// 	// イベントループの開始
// 	mlx_loop(game.mlx);

// 	return (0);
// }
