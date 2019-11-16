let app = Express.App.make();
let getUrl = (path, query) => {
  let url: ReasonReactRouter.url = {
    path:
      List.filter(s => s != "", Array.to_list(Js.String.split("/", path))),
    hash: "",
    search:
      switch (Js.Dict.get(query, "success")) {
      | Some(v) =>
        switch (Js.Json.decodeString(v)) {
        | Some(s) =>
          switch (s) {
          | "true" => "success=true"
          | "false" => "success=false"
          | _ => ""
          }
        | _ => ""
        }
      | _ => ""
      },
  };
  url;
};
let renderHTML = (_next, _req, res) => {
  // let url = getUrl(Express.Request.path(_req), Express.Request.query(_req));
  // let content = ReactDOMServerRe.renderToString(<Router serverUrl=(Some(url)) />);
  let serverUrl = Routes.serverMatch(Express.Request.path(_req));
  let content = ReactDOMServerRe.renderToString(<Router serverUrl=(Some(serverUrl)) />);
  // let content = ReactDOMServerRe.renderToString(<App />);
  Express.Response.sendString(Template.make(~content, ~title="ReasonReact SSR Starter", ()), res);
};

Express.Static.defaultOptions()
|> Express.Static.make("dist/")
|> Express.Static.asMiddleware
|> Express.App.useOnPath(app, ~path="/dist");

Express.Static.defaultOptions()
|> Express.Static.make("static/")
|> Express.Static.asMiddleware
|> Express.App.useOnPath(app, ~path="/static");

renderHTML |> Express.Middleware.from |> Express.App.useOnPath(~path="/", app);

let port = 3000;

let onListen = e =>
  switch e {
  | exception (Js.Exn.Error(e)) =>
    Js.log(e);
    Node.Process.exit(1);
  | _ => Js.log("Listening at http://localhost:" ++ string_of_int(port))
  };

Express.App.listen(app, ~onListen, ~port, ());
