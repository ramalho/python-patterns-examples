import feedparser
import urllib2

class AbstractNewsParser(object):
    def __init__(self):
        # Prohibit creating class instance
        if self.__class__ is AbstractNewsParser:
             raise TypeError('abstract class cannot be instantiated')

    def get_top_news(self):
        """A Template method.

        Returns 3 latest news for every news website.

        """
        url = self.get_url()
        raw_content = self.get_raw_content(url)
        content = self.parse_content(raw_content)
        if self.max_articles_hook():
            return self.crop(content, max_articles=self.max_articles_hook())
        return self.crop(content)

    def get_url(self):
        raise NotImplementedError()

    def get_raw_content(self, url):
        return urllib2.urlopen(url).read()

    def parse_content(self, content):
        raise NotImplementedError()

    def crop(self, parsed_content, max_articles=3):
        last_items = parsed_content['entries'][:max_articles]
        return [item['title'] for item in last_items]

    def max_articles_hook(self):
        pass


class BbcParser(AbstractNewsParser):
    def get_url(self):
        return 'http://feeds.bbci.co.uk/news/rss.xml'

    def parse_content(self, content):
        content = feedparser.parse(content)
        # Do some transfomarion with content
        return content

class ReuterParser(AbstractNewsParser):
     def get_url(self):
        return 'http://feeds.reuters.com/reuters/topNews?format=xml'

     def parse_content(self, content):
        content = feedparser.parse(content)
        # Do some transfomarion with content
        return content

     def max_articles_hook(self):
        return 5

if __name__ == '__main__':
    bbc = BbcParser()
    print 'BBC: \n', '\n'.join(bbc.get_top_news())

    reuter = ReuterParser()
    print 'REUTER: \n', '\n'.join(reuter.get_top_news())
