library(ggplot2)
df = read.csv("out.csv",sep=";",header = TRUE, strip.white= TRUE)

ggplot(df, aes(x = N, y = time*1000 , color = Algo)) + 
geom_line() + geom_point()
 
ggsave("output.pdf", width = 7, height = 5)
