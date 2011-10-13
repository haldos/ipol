"""
demo example for the threshold
"""

from lib import base_app, build, http, image
from lib.misc import app_expose, ctime
from lib.base_app import init_app
import cherrypy
from cherrypy import TimeoutError
import os.path
import shutil

class app(base_app):
    """ template demo app """
    
    title = "Combined Local Global"
    input_nb = 2 # number of input images
    is_test = True       # switch to False for deployment

    def __init__(self):
        """
        app setup
        """
        # setup the parent class
        base_dir = os.path.dirname(os.path.abspath(__file__))
        base_app.__init__(self, base_dir)

        # select the base_app steps to expose
        # index() is generic
        app_expose(base_app.index)
        app_expose(base_app.input_select)
        app_expose(base_app.input_upload)
        # params() is modified from the template
        app_expose(base_app.params)
        # run() and result() must be defined here

    def build(self):
        """
        program build/update
        """

    @cherrypy.expose
    @init_app
    def wait(self, alpha="1.0", rho="0.0", sigma="0.0", numit="50"):
        """
        params handling and run redirection
        """
        # save and validate the parameters
        try:
            self.cfg['param'] = {'alpha' : float(alpha)}
	    self.cfg['param'] = {'rho' : float(rho)}
	    self.cfg['param'] = {'sigma' : float(sigma)}
	    self.cfg['param'] = {'numit' : int(numit)}
            self.cfg.save()
        except ValueError:
            return self.error(errcode='badparams',
                              errmsg="The parameter must be numeric.")

        http.refresh(self.base_url + 'run?key=%s' % self.key)
        return self.tmpl_out("wait.html")

    @cherrypy.expose
    @init_app
    def run(self):
        """
        algo execution
        """
        # read the parameters
        alpha = self.cfg['param']['alpha']
	rho = self.cfg['param']['rho']
	sigma = self.cfg['param']['sigma']
	numit = self.cfg['param']['numit']
        # run the algorithm
        try:
            self.run_algo(alpha,rho,sigma,numit)
        except TimeoutError:
            return self.error(errcode='timeout') 
        except RuntimeError:
            return self.error(errcode='runtime')
        http.redir_303(self.base_url + 'result?key=%s' % self.key)

        return self.tmpl_out("run.html")

    def run_algo(self, alpha, rho, sigma, numit):
        """
        the core algo runner
        could also be called by a batch processor
        this one needs no parameter
        """
        p = self.run_proc(['test_clg_flow', 'input_0.png','input_1.png', str(alpha), str(rho), str(sigma), str(numit),
                           'output.png'])
        self.wait_proc(p, timeout=self.timeout)
        return

    @cherrypy.expose
    @init_app
    def result(self):
        """
        display the algo results
        """
        return self.tmpl_out("result.html",
                             height=image(self.work_dir
                                          + 'output.png').size[1])
