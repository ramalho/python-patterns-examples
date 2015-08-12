# redirect function is used to forward user to full url if he came from shortened
# request is used to encapsulate HTTP request. 
# It will contain request methods, # request arguments 
# and other related information
from flask import redirect, render_template, request, Flask
from werkzeug.exceptions import BadRequest, NotFound

import models

# Initialize Flask application
app = Flask(__name__, template_folder='views')

@app.route("/")
def index():
    """Renders main page."""
    return render_template('main_page.html')

@app.route("/shorten/")
def shorten():
    """Returns short_url of requested full_url."""
    # Validate user input
    full_url = request.args.get('url')
    if not full_url:
        raise BadRequest()

    url_model = models.Url.shorten(full_url)

    # Pass data to view and render
    short_url = request.host + '/' + url_model.short_url
    return render_template('success.html', short_url=short_url)

@app.route('/<path:path>')
def redirect_to_full_url(path=''):
    """Gets short url and redirects user to corresponding full url if found."""
    url_model = models.Url.get_by_short_url(path)

    if not url_model:
        raise NotFound()

    return redirect(url_model.full_url)


if __name__ == "__main__":
    app.run(debug=True)
