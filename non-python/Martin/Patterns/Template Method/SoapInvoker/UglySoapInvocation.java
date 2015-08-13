public void sendCode(int code)
{
	SoapInvoker i = new SoapInvoker("some uri", "sendCode")
	{
		private int itsCode;
		public void setCode(int code)
		{
			itsCode = code;
		}
		public void setParams()
		{
			d_params.addElement(
				new Parameter(
					"code", int.class, new Integer(itsCode), null
				)
			);
		}
	}.setCode(code);
	i.invoke();
}
	
