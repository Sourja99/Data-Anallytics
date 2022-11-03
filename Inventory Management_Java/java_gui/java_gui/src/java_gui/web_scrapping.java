/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package java_gui;

import java.io.IOException;	
import java.io.*;

import org.jsoup.*;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;


public class web_scrapping {
	//static String productname = "Hele";
              
	public static void main(String[] args) throws IOException {
            	  String productname ="";
		String productcolor ="";
		String productsize ="";
		String productpriceoff ="";
		String productprice ="";
		String productdes ="";
		String productlink ="";
		String productimage ="";
		Document document = Jsoup.connect("https://www.amazon.in/Dove-Nourishers-Nourishment-Effectively-Nourishing/dp/B09TP6JR5N/ref=asc_df_B09TP6JR5N/?tag=googleshopdes-21&linkCode=df0&hvadid=586318552267&hvpos=&hvnetw=g&hvrand=5269437151503089261&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9062098&hvtargid=pla-1640800640620&psc=1")
				.timeout(6000).get();
		Elements elementimage = document.select("div[class=imgTagWrapper] > img");   
//                Elements ele=document.select("#a-section a-spacing-small a-spacing-top-small");
//                ele.forEach((e)->{
//                    System.out.println(e.html());
//                });
                //select("div.id()");
		//for(Element e:body.)
		for (Element e1 : elementimage) {
			productimage = e1.attr("src");
			//String productimgurl = productimage; 
		}
		
		Elements elementname = document.getElementsByClass("a-size-large product-title-word-break");       //select("div.id()");
		//for(Element e:body.)
		for (Element e2 : elementname) {
			productname = e2.text();
                     
                        
		}
                
 //#################               
                
//		Elements elementnames = document.getElementsByClass("a-section a-spacing-small a-spacing-top-small");       //select("div.id()");
//		//for(Element e:body.)
//		for (Element e2 : elementnames) {
////			System.out.println(e2.html());
//                        Elements text=e2.select("span");
//                        String s1 = null;
//                        for (Element e3:text){
////                            System.out.println(e3.text());
//                              s1 = s1+(e3.text());
//                        }
//                        System.out.println(s1);
//                        
//                        
//		}
//                
                
  //#################                
                
                
                Elements els = document.getElementsByClass("a-section a-spacing-small"); 
//                Elements els = document.select("div[class=a-section a-spacing-small] > span");   
                
                for (Element e3 : els) {
//                        System.out.println(e3.html());
                        Elements text=e3.select("span");
                        String s1 ="";
                        for (Element e4:text){
//                            System.out.println(e3.text());
                              s1 = s1+(e3.text());
                        }
                        System.out.println(s1);
                        productdes=s1;
		}
                 
		Elements elementpriceoff = document.getElementsByClass("a-size-large a-color-price savingPriceOverride aok-align-center reinventPriceSavingsPercentageMargin savingsPercentage");       //select("div.id()");
		//for(Element e:body.)
		Elements elementprice = document.getElementsByClass("a-price-whole");
		
		for (Element e3 : elementpriceoff) {
			productpriceoff = e3.text();
			for(Element e4 : elementprice) {
				productprice = e4.text();
				}
		}
		
	
		//String e4 = elementprice.text();
		
		System.out.println(productimage);
                System.out.println("#########");
		System.out.println(productname);
                
		  System.out.println("#########");
		System.out.println(productpriceoff);
                  System.out.println("#########");
		System.out.println(productprice.replace(".","/-")); 
    }

}
