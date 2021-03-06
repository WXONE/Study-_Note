# CS224 Skip-Gram神经网络语言模型

## 导学：

## 什么是自然语言处理？

本质上与计算机语言学是同义的，他横跨了计算机科学、语言学、和人工智能，我们想要做的，就是让电脑用人类的语言做一些事情，能够理解和使用人类语言进行自我表达，像人类一样。我们知道人工智能的应用有很多，如计算机视觉、智能机器人等，但是语言是人工智能中一个非常特殊的部分，因为语言是人类的特有属性我们都是通过语言来思考和行动的，地球上很多生物都有视觉系统，但是只有人类拥有语言，所以，理解语言、使用语言是人类的特权，如果一台计算机能够欺骗人类，让人相信它是人类，那么该计算机就是智能的。

## 自然语言处理无处不在

1. 微软小冰是中国微博上的一款将对话带入我们日常生活的聊天机器人。百万年轻中国用户通过小冰交换信息，与他人分手、丢了工作或感觉沮丧时，人们经常会和小冰聊天。到目前，小冰已经累积了上亿用户，平均聊天的回数23轮，平时聊天时长大概是25分钟左右。
2. 2016年秋天谷歌翻译推出了一个全新升级的人工智能翻译引擎。这样一来，曾以产出语言生硬但又可用的翻译而闻名的谷歌翻译，已开始产出语言流畅、精确度高的翻译文本。对未经专业翻译训练的人来说，这种文本输出几乎与人工翻译并未有区别。

![1558160828702](D:\Study-_Note\NLP\斯坦福自然语言处理\图片\%5CUsers%5CWXONE%5CAppData%5CRoaming%5CTypora%5Ctypora-user-images%5C1558160828702.png)

3. 文本分类：文本分类是指给定一个文本，预测其所属的预定类别。一种流行文本分类应用是情感分析其中的常用类别标签表示源文本的情绪色调，例如“积极”或“消极”。其他3类文本分类的应用：

   垃圾邮件过滤，依照文本分类电子邮件的垃圾邮件。

   语言识别，对源文本的语言进行分类。

   题材分类，分类虚构故事的体裁。

   此外，还可以按需要给文本分配多个类别标签（即所谓的多标签分类）。 例如为tweet分配多个主题标签。

4. 语言建模
   问题是预测出给定单词的下一个单词。 该任务是语音或光学字符识别的基础，也用于拼写校正，手写识别和统计学的机器翻译。
   语言模型可以学习词与词之间的概率关系，然后生成与源文本统计上一致的词汇新序列。

   语言模型可以用于文本或语音生成，应用如下：

   生成新的文章标题。

   生成新的句子，段落或文档。

   生成后续句子建议。

5. 语音识别
   语音识别的任务是将包含口语在内的自然语言的声学信号转换成符合说话者预期的相应的单词序列。语言模型用于创建以音频数据为基础的的输出文本，应用包括：

   生成演讲文本。

   为电影或电视节目创建字幕。

   开车时向收音机发出命令。

6. 说明生成
   说明生成是解决如何描述图像内容的问题，依照诸如照片等的数字图像生成和图像内容相关的文本描述。

   说明生成的语言模型用于根据图像生成标题，一些具体的应用包括：

   描述场景的内容

   创建照片的标题

   描述视频

7. 等

## 处理语言的思路

在学习NLP技术的过程中，我们希望大家能够学到对人类语言的欣赏，比如语言有哪些层次，对每个层次是如何处理的等

![1558161440933](D:\Study-_Note\NLP\斯坦福自然语言处理\图片\%5CUsers%5CWXONE%5CAppData%5CRoaming%5CTypora%5Ctypora-user-images%5C1558161440933.png)

这幅图是人们对语言层次的传统描述，从输入开始，一般是语音输入，在你的大脑中会进行语音和音位分析来理解这句话，当然也经常以文字的形式，如果是文字输入的过程，与语言学就不是非常沾边，我们通常用OCR文字识别技术对文本做文字识别，然后经过一系列复杂的处理过程：

> 1. 形态分析
> 2. 语法分析
> 3. 语义解释
> 4. 语言处理

我们得出复杂词汇的含义，如`incomprehensible `这个词由in做前缀，有ble做后缀，这是对单词结构形态的分析，然后我们试着理解句子的结构，做句法分析，如果有一句话“您就是扎神？”在这里，您是主语，是或者就是是谓语，扎神是宾语，接着做语义理解得出句子含义，但是仅仅知道句子中每个词的含义不足以真正理解人类语言，许多含义是通过上下文来传达的，这就引出了语用学和语篇处理等研究领域，在自然语言处理的学习中我们将集中大部分时间讨论句法分析和语义理解。当然今天只是简单讲一下。







我将把我的项目经验结合CS224n的前两讲的内容与大家交流。

我们知道，不论你是在处理图像还是别的什么东西，计算机都将把他们视为向量或者矩阵，简单来说就是一堆乱七八糟的数字和一堆乱七八糟的符号。那么我们怎么将文本内容转换为矩阵或者向量呢，今天介绍几种方法

如果你在词典里查meaning的意思，韦氏词典对meaning的表述是：用单词、短语等表示的想法，人们想要通过单词、符号表达的想法，从单词的角度讲，这非常接近于语言学上最常理解的meaning的含义，在标准的语言学中，单词指代了一种符号，他代表世界上的某些具体事物，比如说鼠标，我的鼠标，和世界上所有的鼠标，就是“鼠标”一词的指代物，目前这种对meaning的解释并未应用到计算机技术中。

到目前为止，最常见的办法是用分类资源来处理词义，在英语中最著名的分类资源是WordNet。他展示了很多分类。

```python
from nltk.corpus import wordnet as wn
panda = wn.synset('panda.n.01')
hyper = lambda s : s.hypernyms()
list[panda.colsure(hyper)]
```

用nltk导入wordnet包

但是使用WordNet会使人们遗漏掉很多细节，人们在使用词汇的时候会更加灵活，比如说，`i am a deep-learning ninja`,这在WordNet语料库里就没有。人们往同义词集里面加什么词是一个非常主观的选择，你如何区分一个词有哪些含义，那些词是不一样的，是非常模糊的选择。最终很难对词汇的相似性给出准确的含义。这就是一个问题，这就是离散化表征普遍存在的问题，现在需要注意的问题是，几乎所有的NLP研究，除了现代深度学习，以及八十年代所做的一点NLP神经网络外，几乎所有的NLP都使用了原子符号来表示单词，这个原子符号就是我们接下来要说的词向量。

## 1. 词向量

​	最早的词向量是很冗长的，它使用词向量维度大小为整个词汇表的大小，对于每个具体的词汇表中的词，将其对应的位置设置为1.比如我们有下面的5个词组成的词汇表，词"Queen"的序号为2， 那么它的词向量就是(0,1,0,0,0)(0,1,0,0,0)。同样的道理，词"Woman"的词向量就是(0,0,0,1,0)(0,0,0,1,0)。这种词向量的编码方式我们一般叫做1-of-N representation或者one hot representation.（独热编码），独热编码表示词向量非常简单，但是问题也很明显，最大的问题就是我们的词汇非常大，wiki中文语料库的容量高达1.6GB，一个汉字所占16Byte，可想而知这个语料库里要有多少汉字。所以在这时候我们就需要一个百万维的向量来表示，但是这对内存来说就是一场灾难。这样的向量其实除了一个位置是1，其余全是0，表达的效率很低。任意两个词的独热编码都是正交的，` 两个向量 a = [a1, a2,…, an]和b = [b1, b2,…, bn]的点积定义为：a·b=a1b1+a2b2+……+anbn。 ` 这就体现出一个问题：他不能给出任何词汇之间的内在关系概念。当然我们可以使用独热编码去完成一些任务，但是这里我不建议大家这样做。

比如说king 、 queen 、 man 、woman 、child

(画图)

![img](D:\Study-_Note\NLP\斯坦福自然语言处理\图片\1042406-20170713145606275-2100371803.png)

​	

我们可以选择一种直接的方法， 一个单词所表示的含义，是你可以直接阅读的，在这些表示中，你就可以看出相似性，我们要做的就是构建这些向量，然后做一些类似求解点积的操作。

我们应该怎么做呢，我们就需要使用这个十分简单，极其玄妙，又应用广泛的NLP技术，称作分布相似性（distributional  similarity）。分布相似性是指，你可以得到大量表示某个词汇含义的值，只需通过观察其出现的上下文，并对这些上下文做一些处理来得到。这是一种关于词汇语义的理论。

`government debt problems turning into banking crises as has happended in saying that Europe needs unified banking regulation to replace the hodgepodge`

在这个语料库中，如果我想知道 `banking `这个单词的意思，我需要做的就是找到数个这个单词出现的句子，然后观察他每一次出现的语境，我会看到他的上下文：......等等等等，然后我开始统计所有出现过的内容，通过某种方式用这些上下文中的词来表示banking的含义 。

​	具有相似上下文的词，应该有相似的语义，这个假说被称为distributional hypothesis，分布式表示就是一种能够刻画语义之间的相似度并且维度较低的稠密向量表示，例如：

>高兴=[0.2,1.6,−0.6,0.7,0.3]T
>
>开心=[0.3,1.4,−0.5,0.9,0.2]T

这样，便可通过计算向量的余弦相似度，来反映出词的语义相似度。

余弦相似度计算：

![img](D:\Study-_Note\NLP\斯坦福自然语言处理\图片\20131111175301140)

![img](D:\Study-_Note\NLP\斯坦福自然语言处理\图片\20131111175458906)

如果向量a和b不是二维而是n维，上述余弦的计算法仍然正确。假定a和b是两个n维向量，a是  ，b是  ，则a与b的夹角 的余弦等于：

![img](https://img-blog.csdn.net/20131111175544093)

余弦值越接近1，就表明夹角越接近0度，也就是两个向量越相似，夹角等于0，即两个向量相等，这就叫"余弦相似性"。



Distributed representation（分布式表示）可以解决One hot representation的问题，它的思路是通过训练，将每个词都映射到一个较短的词向量上来。所有的这些词向量就构成了向量空间，进而可以用普通的统计学的方法来研究词与词之间的关系。这个较短的词向量维度是多大呢？这个一般需要我们在训练时自己来指定。

分布式表示的含义与之前讲过的词汇含义的指称是完全不一样的，鼠标的意思是指我们手里的一个个具体的鼠标，这就有异于分布式表示。分布式表示又与独热编码不同，独热编码是一种存储在某处的本地表示，对于某个词，我们在所有任务中，他的独热编码都是固定的

当我们拿到一个语料库时，我们首先要对其进行清洗、分词（明天再讲），之后我们要做的就是给每一个单词构造一个向量，我们会选择一个密集型向量，让她可以预测目标单词所在文本的其他词汇。

所有其他词汇也是由一个个单词构成的，我们看一下相似性测量的方法，比如两个向量间的点积，我们将对他进行一些修改，以便于它可以预测，我们有很多算法来完成这些工作，这样以来这些词汇就可以预测上下文的其他词汇，也可以通过他上下文的词汇来预测他 。

​	　比如下图我们将词汇表里的词用"Royalty","Masculinity", "Femininity"和"Age"4个维度来表示，King这个词对应的词向量可能是(0.99,0.99,0.05,0.7)(0.99,0.99,0.05,0.7)。当然在实际情况中，我们并不能对词向量的每个维度做一个很好的解释。

![img](D:\Study-_Note\NLP\斯坦福自然语言处理\图片\1042406-20170713150625759-1047275185.png)

　　有了用Distributed Representation表示的较短的词向量，我们就可以较容易的分析词之间的关系了，比如我们将词的维度降维到2维，有一个有趣的研究表明，用下图的词向量表示我们的词时，我们可以发现：

![img](D:\Study-_Note\NLP\斯坦福自然语言处理\图片\1042406-20170713151608181-1336632086.png)

​						King→−Man→+Woman→=Queen→

 　　　　可见我们只要得到了词汇表里所有词对应的词向量，那么我们就可以做很多有趣的事情了。不过，怎么训练得到合适的词向量呢？一个很常见的方法是使用神经网络语言模型。



ok这是第一部分，现在我们进入第二部分，一个谷歌推出的工具：Word2Vec

从字面上看很好理解，就是Word to vector 单词 -> 向量。

Word2Vec目标函数的梯度：简单介绍Word2Vec，我们想要获取一个词向量，将他作为一个词义模型，这其实是一个有争议的想法，我先来介绍一下来龙去脉，然后深入研究。什么是Word2Vec。

# Word2Vec

这是我们一种通用的方法来学习神经词嵌入问题(neural word embedding)。

我们定义一个模型，通过中心词汇预测他上下文的词汇，就像上面讲过的分布式学习。我们有一些概率的方法来实现。接下来，我们用损失函数来判断预测的准确性。理想状态下，我们可以准确预测中心词汇周围的词

![1557753074186](D:\Study-_Note\NLP\斯坦福自然语言处理\图片\%5CUsers%5CWXONE%5CAppData%5CRoaming%5CTypora%5Ctypora-user-images%5C1557753074186.png)

wt是中心词汇，w-t是除了他以外的所有其他的上下文。



这里的-t表示环绕在t中心词周围的其他单词，如果我们能准确预测这些词，则 J = 0，我们就没有损失，但是正常情况下我们做不到这一点，我们得到了损失函数将会在语料库的各个地方执行这种预测操作，目的是调整词汇表示，从而使损失最小化。

但是，你实际上除了设置一个这样的预测目标外，其他的什么也没做，或者说做不了，只是让每个单词的向量都能预测其周围的词汇。你只是顶下这样简明的目标，其他的什么也没做，这就是深度学习的魅力。所以我们要深究一下细节，看看这些是如何实现的。

如果我们只想得到好的单词表示，我们甚至不需要构建一个可以预测的概率语言模型，我们只需要知道一种学习单词表示的方法。 这就是Word2Vec模型。

Word2Vec模型的核心是构建一个很简单的、可扩展的、快速的训练模型，让我们可以处理数十亿单词的文本，并生成非常棒的向量表示。

Word2Vec模型尝试去做的最基本的事就是利用语言的意义理论，来预测每个单词和他的上下文词汇，word2vec是一个软件，里面有两个生成词向量的算法，里面还有两套效率中等的训练方法，今天我们只讲一个成为skip-gram的方法

![1557754170789](D:\Study-_Note\NLP\斯坦福自然语言处理\图片\%5CUsers%5CWXONE%5CAppData%5CRoaming%5CTypora%5Ctypora-user-images%5C1557754170789.png)

# Skip-Gram用于神经网络语言模型

![1557754236210](D:\Study-_Note\NLP\斯坦福自然语言处理\图片\%5CUsers%5CWXONE%5CAppData%5CRoaming%5CTypora%5Ctypora-user-images%5C1557754236210.png)

![1557795620190](D:\Study-_Note\NLP\斯坦福自然语言处理\图片\%5CUsers%5CWXONE%5CAppData%5CRoaming%5CTypora%5Ctypora-user-images%5C1557795620190.png)



这是一张Skip-Gram模型的图，这个模型的概念是，在每一个估算步都取一个词作为中心词汇，我们仍然用上面的那个语料：

`government debt problems turning into banking crises as has happended in saying that Europe needs unified banking regulation to replace the hodgepodge`

这里我们选择中心词banking，尝试用他去预测一定范围内的上下文词汇，所以这个模型将定义一个概率分布，即给定一个中心词汇，计算某个单词在他上下文中出现的概率，我们选取词汇的向量表示，让概率分布值最大化，这个模型只有一个概率分布，并不是左边的词汇和右边的词汇各有一个概率分布，对一个词汇，我们有且仅有一个概率分布，这个概率分布就是模型的输出，接下来我们要做的就是定义一个半径m，然后从中心词汇开始，到距离为m的位置来预测周围的词汇。我们要选择词汇向量，以便于让预测的概率达到最大，因此损失函数，或者说目标函数，就是这里的J‘。

![1557794066102](D:\Study-_Note\NLP\斯坦福自然语言处理\图片\%5CUsers%5CWXONE%5CAppData%5CRoaming%5CTypora%5Ctypora-user-images%5C1557794066102.png)

J’表示的是当我们拿到一段很长的文本，然后遍历文本中所有位置，对于文本中的每个位置，我们都会定义一个围绕中心词汇的大小为2m的窗口，中心词前后各m个单词，这样就得到一个概率分布，可以根据中心词汇给出其上下文的词汇出现的概率。然后我们要调整模型的参数，使这个概率尽可能地高，这个参数就是 θ 

 θ  就是词向量，也是这个模型唯一的参数。这里就有人会问了，m不也是参数吗，其实这是超参数，这个模型有很多超参数，除了m，还有几个容差系数。J‘就是目标函数，但是我们要对他做一些调整，因为，首先处理概率问题是一件很不爽的事情，我们要做最大化操作，实际上就是解决对数分布问题，这样所有的求积就会转换成求和，我们有了对数概率分布（对概率的乘积取对数，把累乘转换为累加），然后求和，这样我们就不用计算整个语料库的概率，而是取每个位置的平均值，这样相当于对每个词汇进行归一化处理，这样并不影响最大值。其实我们在实现的时候，最喜欢的是最小化操作，而不是最大化操作，因为归一化因子计算量太大，这一点在你研究的过程中就会慢慢体会到，所以我们现在在这个方程的前面加一个负号，这样我们就得到一个负的对数似然函数，也就是模型的负对数分布，这就是我们要正式最小化的目标函数。负的对数似然意味着我们使用的是交叉熵损失函数，这个知道就行。

![1557796488140](D:\Study-_Note\NLP\斯坦福自然语言处理\图片\%5CUsers%5CWXONE%5CAppData%5CRoaming%5CTypora%5Ctypora-user-images%5C1557796488140.png)

我们再来看一下我们是怎么利用这些单词向量来最小化负的对数似然函数的呢，我们采用的方法是，根据由单词向量构造而成的中心词汇，来得出其上下文单词的概率分布，概率分布的形式如上式。

在这个式子里，c 和 o 分别输入及输出的单词的index，以及他的类型，t和t+j是单词在文本中的位置，这个比如说o是73，c是47，那么这个概率就是73号词在47号中心词条件下的出现概率。每种单词类型都有一个对应的向量，Uo是索引为o的单词对应的向量，Vc是中心词对应的向量。我们怎么才能确定相应的概率分布呢，我们要使用一种名为Softmax的模型。

![1557797877908](D:\Study-_Note\NLP\斯坦福自然语言处理\图片\%5CUsers%5CWXONE%5CAppData%5CRoaming%5CTypora%5Ctypora-user-images%5C1557797877908.png)

现在我们过一下这个过程：

从文本中取出两个向量，然后求他们的点积，然后将所得的所有点积求和，两个向量的相似性越大，这个点积就越大。这个模型的思想是通过点积衡量相似性。一旦我们得到两个向量的点积，我们就把他们转换成Softmax形式，

![1557798289605](D:\Study-_Note\NLP\斯坦福自然语言处理\图片\%5CUsers%5CWXONE%5CAppData%5CRoaming%5CTypora%5Ctypora-user-images%5C1557798289605.png)

这是一种将数值转换为概率的标准方法，当计算点积时他们仅仅是实数，我们不能把他们转换成概率，最简单的做法就是把他们转换成指数，因为只要你求一个数的指数，其结果一定落在一个正区间内，那么结果一定为正，这就为求解概率分布提供了一个良好的基础，遍历了整个文本后，我们得到了大量结果为正的数据，这时候我们只需要将他们求和然后用各项除以总和就可以得到他们等比例的概率分布，接下来就是对这个概率进行归一化处理。

ok这就是skip-gram模型的原理，现在我们看一下他在计算机中是怎样运行的;

![mmexport1557801375439](D:\QQ接收文件\MobileFile\mmexport1557801375439.jpg)



这些单词向量让我们的预测尽可能的准确，我们会将模型中的参数都放进一个大的向量θ里，然后我们进行优化，通过改变这些参数，让模型的目标尽可能的优化，我们要的参数就是，对于每个单词，我们都有一个d维的小向量，不管他是中心词汇还是上下文词汇。所以在θ中包含了中心向量和上下文向量，所以θ的大小是2d。在这里我们只是用θ来模糊的表示位置参数，在skip-gram里可以把他理解为两个矩阵，他是我们要优化的对象。

