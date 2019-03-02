import java.util.ArrayList;
import java.util.Scanner;

//http://trainingcenter.ufps.edu.co/problemas/329/detalle/es

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String a;
        while (sc.hasNext()) {

            a = sc.nextLine();
            String jugadas[] = a.split(" ");
           
           
            int num = 0;
            int p1 = 0;
            int p2 = 0;
            int m1 = 0;
            int m2 = 0;
            int p11 = 0;
            int p22 = 0;
            int imp_1 = 0;
            int imp_2 = 0;
            int max_1 = 0;
            int max_2 = 0;
            int[] cesta_1 = new int[16];
            int[] cesta_2 = new int[16];
            int[] pasos = new int[16];
            for (int i = 0; num<15; i++) {
                String p[] = jugadas[i].split("-");
                int jugador = Integer.parseInt(p[0]);
                int bolita = Integer.parseInt(p[1]);

                if (bolita > num + 1) {
                    if (jugador == 1) {
                        m1 += bolita;
                    } else {
                        m2 += bolita;
                    }
                } else if (bolita == 0) {
                    if (jugador == 1) {
                        m1 += num + 1;
                    } else {
                        m2 += num + 1;
                    }
                } else if(bolita==num+1) {
                    num++;
                    if (jugador == 1) {
                        cesta_1[bolita] = bolita;
                    } else {
                        cesta_2[bolita] = bolita;
                    }
                }
            }

            //paso 1
            for (int i = 1; i < 16; i++) {
                p1 += cesta_1[i];
                p2 += cesta_2[i];
            }
            if (p1 != p11) {
                pasos[1]++;
            }
            if (p2 != p22) {
                pasos[1]++;
            }
            p11 = p1;
            p22 = p2;

            if (p1 > m1) {
                p1 += 2;
            }
            if (p2 > m2) {
                p2 += 2; //paso 2
            }
            if (p1 != p11) {
                pasos[2]++;
            }
            if (p2 != p22) {
                pasos[2]++;
            }
            
            p11 = p1;
            p22 = p2;

            p1 = p1 - m1;
            p2 = p2 - m2;//paso 3
            if (p1 != p11) {
                pasos[3]++;
            }
            if (p2 != p22) {
                pasos[3]++;
            }
            p11 = p1;
            p22 = p2;

            if (p1 < 0) {
                p1 += 5;
            }
            if (p2 < 0) {
                p2 += 5;//paso 4
            }
            if (p1 != p11) {
                pasos[4]++;
            }
            if (p2 != p22) {
                pasos[4]++;
            }
            p11 = p1;
            p22 = p2;

            if (p1 == p2) {

                if (m1 > m2) {
                    p2 += 1;
                }
                if (m2 > m1) {
                    p1 += 1;//paso 5
                }
            }

            if (p1 != p11) {
                pasos[5]++;
            }
            if (p2 != p22) {
                pasos[5]++;
            }
            p11 = p1;
            p22 = p2;

            if (p1 >= 0 &&  (int)Math.sqrt(p1) *  (int)Math.sqrt(p1) == p1) {
                p1 += 10;//paso 6
            }
            if (p2 >= 0 &&  (int) Math.sqrt(p2) * (int) Math.sqrt(p2) == p2) {
                p2 += 10;
            }

            if (p1 != p11) {
                pasos[6]++;
            }
            if (p2 != p22) {
                pasos[6]++;
            }
            p11 = p1;
            p22 = p2;

            if (cesta_1[8] == 8) {
                p1 += 10;
            } else if (cesta_2[8] == 8) {
                p2 += 10; //7
            }

            if (p1 != p11) {
                pasos[7]++;
            }
            if (p2 != p22) {
                pasos[7]++;
            }
            p11 = p1;
            p22 = p2;
            
            imp_1=0; imp_2=0;
            for (int i = 1; i < 16; i++) {
                if (i % 2 == 1 && cesta_1[i] == i) {
                    imp_1++;
                }
                if (i % 2 == 1 && cesta_2[i] == i) {
                    imp_2++;
                }
            }
            if (imp_1 > imp_2) {
                p1 += 5;
            }
            if (imp_2 > imp_1) {
                p2 += 5; //8
            }
            
            if (p1 != p11) {
                pasos[8]++;
            }
            if (p2 != p22) {
                pasos[8]++;
            }
            p11 = p1;
            p22 = p2;

            if (imp_1 == 8) {
                p2 += 4;
                p1 -= 4;
                cesta_1[1] = 0;
                cesta_1[3] = 0;
                cesta_2[1] = 1;
                cesta_2[3] = 3;
            }
           else if (imp_2 == 8) {
                p1 += 4;
                p2 -= 4;
                cesta_2[1] = 0;
                cesta_2[3] = 0;
                cesta_1[1] = 1;
                cesta_1[3] = 3;
            }//9
            
            if (p1 != p11) {
                pasos[9]++;
            }
            if (p2 != p22) {
                pasos[9]++;
            }
            p11 = p1;
            p22 = p2;

            int paso_10 = 0;
            int paso_11 = 0;
            for (int i = 1; i < 10; i++) {
                if (pasos[i] >= 1) {
                    paso_10++;
                }
              
            }
         
            if (paso_10 >= 6) {
                max_1 = 0;
                max_2 = 0;
                for (int i = 1; i < 16; i++) {
                    max_1 = Math.max(max_1, cesta_1[i]);
                    max_2 = Math.max(max_2, cesta_2[i]);
                }
               // System.out.println(max_1+" "+max_2);
                p1 = p1 - max_1 + max_2;
                p2 = p2 - max_2 + max_1;

                cesta_1[max_1] = 0;
                cesta_1[max_2] = max_2;
                cesta_2[max_2] = 0;
                cesta_2[max_1] = max_1; //10
            }
          //  System.err.println(p1 + " " + p2);
            if (p1 != p11) {
                pasos[10]++;
            }
            if (p2 != p22) {
                pasos[10]++;
            }
            p11 = p1;
            p22 = p2;
          //  System.out.println(p1 + " " + p2);
            for (int i = 1; i < 10; i++) {
                
                if (pasos[i] == 2) {
                    paso_11++;
                }
                
            }

            if (paso_11 >= 3) {

                max_1 = 0;
                max_2 = 0;
                for (int i = 1; i < 16; i++) {
                    max_1 = Math.max(max_1, cesta_1[i]);
                    max_2 = Math.max(max_2, cesta_2[i]);
                }
              //  cesta_1[max_1]=0;
              //  cesta_2[max_2]=0;
                p1 -= max_1;
                p2 -= max_2;//11
                
				            }
				if (p1 != p11) {
				                pasos[11]++;
				            }
				            if (p2 != p22) {
				                pasos[11]++;
				            }
				            p11 = p1;
				            p22 = p2;
            
            if (p1 % 2 == 0 && p2 % 2 == 0) {
                int inicial = 11;
                for (int i = 11; pasos[i] == 0; i--) {
                	// System.out.println(i+" "+pasos[i]);
                    inicial = i;
                }
                
                for (; inicial >= 1; inicial--) {

                    if (inicial == 11) {
                    	
                  
                        if (paso_11 >= 3) {

                            max_1 = 0;
                            max_2 = 0;
                            for (int i = 1; i < 16; i++) {
                                max_1 = Math.max(max_1, cesta_1[i]);
                                max_2 = Math.max(max_2, cesta_2[i]);
                            }
                         //    cesta_1[max_1]=0;
            			//	 cesta_2[max_2]=0;
                            p1 -= max_1;
                            p2 -= max_2;//11
                        }

                    } else if (inicial == 10) {
                    
                        if (paso_10 >= 6) {
                            max_1 = 0;
                            max_2 = 0;
                            for (int i = 1; i < 16; i++) {
                                max_1 = Math.max(max_1, cesta_1[i]);
                                max_2 = Math.max(max_2, cesta_2[i]);
                            }

                            p1 = p1 - max_1 + max_2;
                            p2 = p2 - max_2 + max_1;

                            cesta_1[max_1] = 0;
                            cesta_1[max_2] = max_2;
                            cesta_2[max_2] = 0;
                            cesta_2[max_1] = max_1; //10
                       //     System.out.println(p1 + " " + p2);
                        }

                    } else if (inicial == 9) {

                        imp_1 = 0;
                        imp_2 = 0;
                        for (int i = 1; i < 16; i++) {
                            if (i % 2 == 1 && cesta_1[i] == i) {
                                imp_1++;
                            }
                            if (i % 2 == 1 && cesta_2[i] == i) {
                                imp_2++;
                            }
                        }

                        if (imp_1 == 8) {
                            p2 += 4;
                            p1 -= 4;
                            cesta_1[1] = 0;
                            cesta_1[3] = 0;
                            cesta_2[1] = 1;
                            cesta_2[3] = 3;
                        }
                        else if (imp_2 == 8) {
                            p1 += 4;
                            p2 -= 4;
                            cesta_2[1] = 0;
                            cesta_2[3] = 0;
                            cesta_1[1] = 1;
                            cesta_1[3] = 3;
                        }//9

                    } else if (inicial == 8) {

                        imp_1 = 0;
                        imp_2 = 0;
                        for (int i = 1; i < 16; i++) {
                            if (i % 2 == 1 && cesta_1[i] == i) {
                                imp_1++;
                            }
                            if (i % 2 == 1 && cesta_2[i] == i) {
                                imp_2++;
                            }
                        }

                        if (imp_1 > imp_2) {
                            p1 += 5;
                        }
                        if (imp_2 > imp_1) {
                            p2 += 5; //8
                        }
                        
                    } else if (inicial == 7) {

                        if (cesta_1[8] == 8) {
                            p1 += 10;
                        } else  if (cesta_2[8] == 8){
                            p2 += 10; //7
                        }

                    } else if (inicial == 6) {

                       if (p1 >= 0 &&  (int)Math.sqrt(p1) *  (int)Math.sqrt(p1) == p1) {
                p1 += 10;//paso 6
            }
            if (p2 >= 0 &&  (int) Math.sqrt(p2) * (int) Math.sqrt(p2) == p2) {
                p2 += 10;
            }

                    } else if (inicial == 5) {

                        if (p1 == p2) {

                            if (m1 > m2) {
                                p2 += 1;
                            }
                           else if (m2 > m1) {
                                p1 += 1;//paso 5
                            }
                        }

                    } else if (inicial == 4) {

                        if (p1 < 0) {
                            p1 += 5;
                        }
                        if (p2 < 0) {
                            p2 += 5;//paso 4
                        }

                    } else if (inicial == 3) {

                        p1 = p1 - m1;
                        p2 = p2 - m2;//paso 3

                    } else if (inicial == 2) {

                        if (p1 > m1) {
                            p1 += 2;
                        }
                        if (p2 > m2) {
                            p2 += 2; //paso 2
                        }

                    } else if (inicial == 1) {
                        for (int i = 1; i < 16; i++) {
                            p1 += cesta_1[i];
                            p2 += cesta_2[i];
                        }
                    }
                }//12

            }
            System.out.println(p1 + " " + p2);
        }
    }

}
