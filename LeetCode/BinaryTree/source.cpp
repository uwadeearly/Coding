/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:16:36 by wei.zhao          #+#    #+#             */
/*   Updated: 2021/11/14 15:21:11 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
float data[] = {
  #include"data.h"
  };
    
int main(int args, char*argv[]){
  for(int i=0; i<4; ++i){
    printf("element: %f\n", data[i]);
  }
  return 0;
}